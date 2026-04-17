#ifndef __DRIVER_GCOMPENSATION_H
#define __DRIVER_GCOMPENSATION_H
/**
 * @brief 重力补偿模块
 * @details 用于根据云台pitch角度与电机电流的关系，计算出补偿系数，从而实现重力补偿
 */

#include "stm32f4xx.h"

/**
 * @brief 重力补偿数据采集结构体
 * @details 用于存储采集的电流和角度数据
 */
typedef struct {
    float current[50];    // 存储电机电流数据
    float pitch[50];      // 存储俯仰角度数据（弧度）
    uint8_t count;        // 数据点数量
    uint8_t max_points;   // 最大数据点数量
    uint8_t initialized;  // 是否初始化
    float compensation_coeff; // 补偿系数
    uint8_t calibrated;   // 是否已完成标定
} GravityCalibration_Type;

/**
 * @brief 初始化重力补偿模块
 * @details 初始化数据存储结构体和相关参数
 */
void Gravity_Calibration_Init(void);

/**
 * @brief 添加标定数据点
 * @param pitch 俯仰角度（度）
 * @param current 电机实际电流
 * @details 在云台抬起过程中添加数据点
 */
void Gravity_Add_Calibration_Point(float pitch, float current);

/**
 * @brief 执行线性拟合计算补偿系数
 * @details 使用最小二乘法拟合数据，计算补偿系数
 */
void Gravity_Perform_Calibration(void);

/**
 * @brief 计算重力补偿电流
 * @param pitch 俯仰角度（度）
 * @return 重力补偿前馈电流值
 * @details 根据角度和补偿系数计算重力补偿
 */
float Gravity_Compensation_Calculate(float pitch);

/**
 * @brief 获取当前补偿系数
 * @return 当前使用的补偿系数
 */
float Gravity_Get_Coefficient(void);

/**
 * @brief 检查是否已完成标定
 * @return 1表示已完成标定，0表示未完成
 */
uint8_t Gravity_Is_Calibrated(void);

#endif /* __DRIVER_GCOMPENSATION_H */
