#ifndef __DRIVER_GCOMPENSATION_H
#define __DRIVER_GCOMPENSATION_H

#include "stm32f4xx.h"

#define GRAVITY_CALIBRATION_MAX_POINTS 400

typedef struct {
    float current[GRAVITY_CALIBRATION_MAX_POINTS]; // motor feedback current, A
    float pitch[GRAVITY_CALIBRATION_MAX_POINTS];   // pitch angle, rad
    uint16_t count;
    uint16_t max_points;
    uint8_t initialized;
    float compensation_coeff;     // sin(theta) coefficient
    float compensation_cos_coeff; // cos(theta) coefficient
    float compensation_bias;      // constant offset
    uint8_t calibrated;
} GravityCalibration_Type;

void Gravity_Calibration_Init(void);
void Gravity_Add_Calibration_Point(float pitch, float current);
void Gravity_Perform_Calibration(void);
float Gravity_Compensation_Calculate(float pitch);
float Gravity_Get_Coefficient(void);
uint8_t Gravity_Is_Calibrated(void);

#endif /* __DRIVER_GCOMPENSATION_H */
