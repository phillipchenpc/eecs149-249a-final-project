#ifndef _ACCELEROMETER_H
#define _ACCELEROMETER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_938279178_H
#define TOP_LEVEL_PREAMBLE_938279178_H
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
} _accelerometer_trigger_t;
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
} _accelerometer_x_t;
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
} _accelerometer_y_t;
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
} _accelerometer_z_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    _accelerometer_trigger_t* _lf_trigger;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    // width of -2 indicates that it is not a multiport.
    #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    int _lf_trigger_width;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    // Default input (in case it does not get connected)
    #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    _accelerometer_trigger_t _lf_default__trigger;
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    _accelerometer_x_t _lf_x;
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    int _lf_x_width;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    _accelerometer_y_t _lf_y;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    int _lf_y_width;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    _accelerometer_z_t _lf_z;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    int _lf_z_width;
    #line 41 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    reaction_t _lf__reaction_0;
    #line 58 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    trigger_t _lf__trigger;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _accelerometer_self_t;
_accelerometer_self_t* new__accelerometer();
#endif // _ACCELEROMETER_H
