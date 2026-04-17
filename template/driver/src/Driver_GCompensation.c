#include "Driver_GCompensation.h"
#include "Driver_Gimbal.h" // 用于获取coefficentTorque2Current等参数
#include "../user/infantry/config.h" // 用于获取CurrentMap_GM6020_Inverse等参数
#include <math.h> // 用于数学函数

GravityCalibration_Type gravityCal;

/**
 * @brief 初始化重力补偿模块
 * @details 初始化数据存储结构体和相关参数
 */
void Gravity_Calibration_Init(void) {
    // 清零数据数组
    for(int i = 0; i < 50; i++) {
        gravityCal.current[i] = 0.0f;
        gravityCal.pitch[i] = 0.0f;
    }
    
    gravityCal.count = 0;
    gravityCal.max_points = 50;
    gravityCal.compensation_coeff = 0.0f;
    gravityCal.initialized = 1;
    gravityCal.calibrated = 0;
}

/**
 * @brief 添加标定数据点
 * @param pitch 俯仰角度（度）
 * @param current 电机实际电流
 * @details 在云台抬起过程中添加数据点
 */
void Gravity_Add_Calibration_Point(float pitch, float current) {
    if (!gravityCal.initialized || gravityCal.calibrated) return;
    
    if (gravityCal.count < gravityCal.max_points) {
        // 将角度转换为弧度
        gravityCal.pitch[gravityCal.count] = pitch * (float)M_PI / 180.0f;
        gravityCal.current[gravityCal.count] = current;
        gravityCal.count++;
    }
}

/**
 * @brief 执行线性拟合计算补偿系数
 * @details 使用最小二乘法拟合数据，计算补偿系数
 */
void Gravity_Perform_Calibration(void) {
    if (!gravityCal.initialized || gravityCal.count < 3) return;
    
    // 使用最小二乘法拟合 I = k * sin(θ) 形式的模型
    // 目标：找到系数k，使得误差平方和最小
    
    float sum_xy = 0.0f;  // sum(current * sin(pitch))
    float sum_xx = 0.0f;  // sum(sin(pitch) * sin(pitch))
    
    for (int i = 0; i < gravityCal.count; i++) {
        float sin_pitch = sinf(gravityCal.pitch[i]);
        sum_xy += gravityCal.current[i] * sin_pitch;
        sum_xx += sin_pitch * sin_pitch;
    }
    
    // 计算补偿系数 k = sum_xy / sum_xx
    if (sum_xx != 0.0f) {
        gravityCal.compensation_coeff = sum_xy / sum_xx;
        gravityCal.calibrated = 1;
    }
}

/**
 * @brief 计算重力补偿电流
 * @param pitch 俯仰角度（度）
 * @return 重力补偿前馈电流值
 * @details 根据角度和补偿系数计算重力补偿，输出补偿电流值
 */
float Gravity_Compensation_Calculate(float pitch) {
    if (!gravityCal.initialized || !gravityCal.calibrated) return 0.0f;
    
    // 将角度转换为弧度
    float pitch_rad = pitch * (float)M_PI / 180.0f;
    
    // 计算补偿电流：I_compensation = coeff * sin(pitch)
    // 注意：重力矩的方向与sin(pitch)相关 
    return gravityCal.compensation_coeff * sinf(pitch_rad);
}

/**
 * @brief 获取当前补偿系数
 * @return 当前使用的补偿系数
 */
float Gravity_Get_Coefficient(void) {
    if (!gravityCal.initialized) return 0.0f;
    return gravityCal.compensation_coeff;
}

/**
 * @brief 检查是否已完成标定
 * @return 1表示已完成标定，0表示未完成
 */
uint8_t Gravity_Is_Calibrated(void) {
    return gravityCal.calibrated;
}