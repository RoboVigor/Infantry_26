#include "Driver_Gimbal.h"

float getGimbalGravityTorque(GyroscopeData_Type * gyroData) {
    float gravityTorque = 0;
    float pitchRad = gyroData->pitch * PI / 180.0f; // 转换为弧度
    gravityTorque = gimbalMass * 9.81f * baryCenterZ * (cosf(pitchRad)*baryCenterX + sinf(pitchRad)*baryCenterZ); // 计算重力矩
    return gravityTorque;
<<<<<<< HEAD
}  
=======
}
>>>>>>> b48ee85b7c1b2fbee508a1118717b58620d696f6
