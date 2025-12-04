#ifndef _ROBOT_H
#define _ROBOT_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_accelerometer.h"
#include "_gyroangle.h"
#include "_motorswithfeedback.h"
#include "_tilt.h"
#ifndef TOP_LEVEL_PREAMBLE_81505591_H
#define TOP_LEVEL_PREAMBLE_81505591_H
#include <math.h>
#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#include <pico/stdlib.h>
#include <imu.h>
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_start_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_side_detect_t;
typedef struct {
    struct self_base_t base;
    
    #line 18 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    float speed;
    #line 19 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    float motor_calibrate;
    #line 26 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    uint32_t last_detect;
    #line 29 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    float* turning_angles;
    #line 30 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    float last_angle;
    #line 37 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    bool direction_up;
    #line 38 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    float roll_max;
    #line 39 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    float pitch_max;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    _robot_start_t* _lf_start;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // width of -2 indicates that it is not a multiport.
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    int _lf_start_width;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // Default input (in case it does not get connected)
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    _robot_start_t _lf_default__start;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    _robot_side_detect_t* _lf_side_detect;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // width of -2 indicates that it is not a multiport.
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    int _lf_side_detect_width;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // Default input (in case it does not get connected)
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    _robot_side_detect_t _lf_default__side_detect;
    struct {
        #line 118 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        _gyroangle_trigger_t trigger;
        #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        _gyroangle_z_t* z;
        #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        trigger_t z_trigger;
        #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        reaction_t* z_reactions[3];
    } _lf_g;
    int _lf_g_width;
    struct {
        #line 31 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
        _encoders_trigger_t trigger;
        #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
        _encoders_left_t* left;
        #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
        trigger_t left_trigger;
        #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
        reaction_t* left_reactions[1];
        #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
        _encoders_right_t* right;
        #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
        trigger_t right_trigger;
        #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
        reaction_t* right_reactions[1];
    } _lf_e;
    int _lf_e_width;
    struct {
        #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        _accelerometer_trigger_t trigger;
        #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        _accelerometer_x_t* x;
        #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        trigger_t x_trigger;
        #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        reaction_t* x_reactions[1];
        #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        _accelerometer_y_t* y;
        #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        trigger_t y_trigger;
        #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        reaction_t* y_reactions[1];
        #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        _accelerometer_z_t* z;
        #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        trigger_t z_trigger;
        #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
        reaction_t* z_reactions[1];
    } _lf_a;
    int _lf_a_width;
    struct {
        #line 32 "/home/foobar/final/lingua_franca/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_left_t left;
        #line 33 "/home/foobar/final/lingua_franca/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_right_t right;
        #line 29 "/home/foobar/final/lingua_franca/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_left_speed_t left_speed;
        #line 30 "/home/foobar/final/lingua_franca/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_right_speed_t right_speed;
    } _lf_m;
    int _lf_m_width;
    struct {
        #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        _tilt_x_t x;
        #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        _tilt_y_t y;
        #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        _tilt_z_t z;
        #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        _tilt_roll_t* roll;
        #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        trigger_t roll_trigger;
        #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        reaction_t* roll_reactions[2];
        #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        _tilt_pitch_t* pitch;
        #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        trigger_t pitch_trigger;
        #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
        reaction_t* pitch_reactions[2];
    } _lf_tilt;
    int _lf_tilt_width;
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_0;
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_1;
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_2;
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_3;
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_4;
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_5;
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_6;
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_7;
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_8;
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_9;
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_10;
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_11;
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t _lf__reaction_12;
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    trigger_t _lf__t;
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    trigger_t _lf__start;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t* _lf__start_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    trigger_t _lf__side_detect;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    reaction_t* _lf__side_detect_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[4];
} _robot_self_t;
_robot_self_t* new__robot();
#endif // _ROBOT_H
