#include "Driver_GCompensation.h"
#include <math.h>

#define GRAVITY_PI 3.14159265358979323846f
#define GRAVITY_DEG_TO_RAD (GRAVITY_PI / 180.0f)
#define GRAVITY_FIT_EPSILON 1.0e-6f

GravityCalibration_Type gravityCal;

void Gravity_Calibration_Init(void) {
    uint16_t i;

    for(i = 0; i < GRAVITY_CALIBRATION_MAX_POINTS; i++) {
        gravityCal.current[i] = 0.0f;
        gravityCal.pitch[i] = 0.0f;
    }

    gravityCal.count = 0;
    gravityCal.max_points = GRAVITY_CALIBRATION_MAX_POINTS;
    gravityCal.compensation_coeff = 0.0f;
    gravityCal.compensation_cos_coeff = 0.0f;
    gravityCal.compensation_bias = 0.0f;
    gravityCal.initialized = 1;
    gravityCal.calibrated = 0;
}

void Gravity_Add_Calibration_Point(float pitch, float current) {
    if (!gravityCal.initialized || gravityCal.calibrated) return;

    if (gravityCal.count < gravityCal.max_points) {
        gravityCal.pitch[gravityCal.count] = pitch * GRAVITY_DEG_TO_RAD;
        gravityCal.current[gravityCal.count] = current;
        gravityCal.count++;
    }
}

void Gravity_Perform_Calibration(void) {
    uint16_t i;
    float ss = 0.0f;
    float cc = 0.0f;
    float sc = 0.0f;
    float s1 = 0.0f;
    float c1 = 0.0f;
    float y_s = 0.0f;
    float y_c = 0.0f;
    float y_1 = 0.0f;
    float n = (float)gravityCal.count;
    float determinant;

    if (!gravityCal.initialized || gravityCal.count < 3) return;

    /*
     * Fit current = a * sin(theta) + b * cos(theta) + c.
     * This keeps the compensation useful even when the mechanical zero is not
     * exactly the gravity-balance angle.
     */
    for (i = 0; i < gravityCal.count; i++) {
        float sin_pitch = sinf(gravityCal.pitch[i]);
        float cos_pitch = cosf(gravityCal.pitch[i]);
        float current = gravityCal.current[i];

        ss += sin_pitch * sin_pitch;
        cc += cos_pitch * cos_pitch;
        sc += sin_pitch * cos_pitch;
        s1 += sin_pitch;
        c1 += cos_pitch;
        y_s += current * sin_pitch;
        y_c += current * cos_pitch;
        y_1 += current;
    }

    determinant = ss * (cc * n - c1 * c1)
                - sc * (sc * n - c1 * s1)
                + s1 * (sc * c1 - cc * s1);

    if (fabsf(determinant) < GRAVITY_FIT_EPSILON) return;

    gravityCal.compensation_coeff =
        (y_s * (cc * n - c1 * c1)
       - sc * (y_c * n - c1 * y_1)
       + s1 * (y_c * c1 - cc * y_1)) / determinant;

    gravityCal.compensation_cos_coeff =
        (ss * (y_c * n - c1 * y_1)
       - y_s * (sc * n - c1 * s1)
       + s1 * (sc * y_1 - y_c * s1)) / determinant;

    gravityCal.compensation_bias =
        (ss * (cc * y_1 - y_c * c1)
       - sc * (sc * y_1 - y_c * s1)
       + y_s * (sc * c1 - cc * s1)) / determinant;

    gravityCal.calibrated = 1;
}

float Gravity_Compensation_Calculate(float pitch) {
    float pitch_rad = pitch * GRAVITY_DEG_TO_RAD;

    if (!gravityCal.initialized || !gravityCal.calibrated) return 0.0f;

    return gravityCal.compensation_coeff * sinf(pitch_rad)
         + gravityCal.compensation_cos_coeff * cosf(pitch_rad)
         + gravityCal.compensation_bias;
}

float Gravity_Get_Coefficient(void) {
    if (!gravityCal.initialized) return 0.0f;
    return gravityCal.compensation_coeff;
}

uint8_t Gravity_Is_Calibrated(void) {
    return gravityCal.calibrated;
}
