#ifndef _ROBOT_H
#define _ROBOT_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_accelerometer.h"
#include "_motorswithfeedback.h"
#ifndef TOP_LEVEL_PREAMBLE_2068499906_H
#define TOP_LEVEL_PREAMBLE_2068499906_H
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#include <pico/stdlib.h>
#include <imu.h>
#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
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
    uint16_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_line_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_line_center_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_line_right_t;
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
} _robot_stop_t;
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
} _robot_cont_t;
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
    
    #line 40 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float target_speed;
    #line 41 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float decceleration;
    #line 43 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float scale;
    #line 44 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float target_speed_scaled;
    #line 45 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float target_deccel_scaled;
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float motor_calibrate;
    #line 50 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float prev_left;
    #line 51 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float prev_time;
    #line 60 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int32_t last_left;
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int32_t last_center;
    #line 62 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int32_t last_right;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float side_detect_gain;
    #line 65 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float center_detect_gain;
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    uint16_t diff_tolerance;
    #line 67 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int32_t min_detect;
    #line 68 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int32_t max_detect;
    #line 69 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float max_feedback_perc;
    #line 75 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float start_time;
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_start_t* _lf_start;
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_start_width;
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_start_t _lf_default__start;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_line_left_t* _lf_line_left;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_line_left_width;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_line_left_t _lf_default__line_left;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_line_center_t* _lf_line_center;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_line_center_width;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_line_center_t _lf_default__line_center;
    #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_line_right_t* _lf_line_right;
    #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_line_right_width;
    #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_line_right_t _lf_default__line_right;
    #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_stop_t* _lf_stop;
    #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_stop_width;
    #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_stop_t _lf_default__stop;
    #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_cont_t* _lf_cont;
    #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // width of -2 indicates that it is not a multiport.
    #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int _lf_cont_width;
    #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Default input (in case it does not get connected)
    #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_cont_t _lf_default__cont;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    _robot_speed_t _lf_speed;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_0;
    #line 89 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_1;
    #line 100 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_2;
    #line 106 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_3;
    #line 117 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_4;
    #line 123 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_5;
    #line 183 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_6;
    #line 192 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_7;
    #line 203 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_8;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__t;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__t_reactions[1];
    #line 190 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__update;
    #line 190 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__update_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__start;
    #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__start_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__line_left;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__line_left_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__line_center;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__line_center_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__line_right;
    #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__line_right_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__stop;
    #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__stop_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__cont;
    #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__cont_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[3];
} _robot_self_t;
_robot_self_t* new__robot();
#endif // _ROBOT_H
