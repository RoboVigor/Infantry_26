#ifndef __DRIVER_GIMBAL_H
#define __DRIVER_GIMBAL_H

#include "Driver_Gyroscope.h"

/* 使用NWU（北西天）坐标系， 对应到车体body系：车体俯视图下，枪管指向方向对齐 +x方向 */
#define baryCenterX 0      // 矢量，云台重心到旋转轴的水平距离，单位为米
#define baryCenterZ 0      // 矢量，云台重心到旋转轴的垂直距离，单位为米
#define gimbalMass 0       // 标量，云台总质量，单位为千克

#define coefficentTorque2Current  (1/0.741f)//转矩转电流系数

/*
 * Function: getGimbalGravityTorque
 * Description: Calculate the gravity torque acting on the gimbal
 * Parameters: gyroData - Pointer to gyroscope data
 * Returns: The calculated gravity torque, if the result is positive, it means the gravity centre is in front of the rotation axis, otherwise it is behind the rotation axis
 * Note: The function defines the axis of motor is aligned with the standard axis of robot. And Tg + Tm = 0 in this situation.
 */
float getGimbalGravityTorque(GyroscopeData_Type * gyroData);


#endif /* __DRIVER_GIMBAL_H */