#ifndef _ROBOT_H
#define _ROBOT_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_accelerometer.h"
#include "_motorswithfeedback.h"
#ifndef TOP_LEVEL_PREAMBLE_253380088_H
#define TOP_LEVEL_PREAMBLE_253380088_H
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
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_speed_t;
typedef struct {
    struct self_base_t base;
    
    #line 38 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float target_speed;
    #line 39 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float decceleration;
    #line 41 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float scale;
    #line 42 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float target_speed_scaled;
    #line 43 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float target_deccel_scaled;
    #line 45 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float motor_calibrate;
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float prev_left;
    #line 49 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float prev_time;
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    uint32_t last_detect;
    #line 106 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float start_time;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_start_t* _lf_start;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_start_width;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_start_t _lf_default__start;
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_side_detect_t* _lf_side_detect;
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_side_detect_width;
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_side_detect_t _lf_default__side_detect;
    #line 50 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_speed_t _lf_speed;
    #line 50 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_speed_width;
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
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_0;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_1;
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_2;
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_3;
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_4;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_5;
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_6;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__t;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__t_reactions[2];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[2];
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__start;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__start_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__side_detect;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[3];
} _robot_self_t;
_robot_self_t* new__robot();
#endif // _ROBOT_H
