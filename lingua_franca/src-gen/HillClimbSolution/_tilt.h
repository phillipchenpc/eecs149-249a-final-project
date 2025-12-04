#ifndef _TILT_H
#define _TILT_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_542019831_H
#define TOP_LEVEL_PREAMBLE_542019831_H
#include <math.h>
#endif
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
} _tilt_x_t;
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
} _tilt_y_t;
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
} _tilt_z_t;
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
} _tilt_pitch_t;
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
} _tilt_roll_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_x_t* _lf_x;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // width of -2 indicates that it is not a multiport.
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    int _lf_x_width;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Default input (in case it does not get connected)
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_x_t _lf_default__x;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_y_t* _lf_y;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // width of -2 indicates that it is not a multiport.
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    int _lf_y_width;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Default input (in case it does not get connected)
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_y_t _lf_default__y;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_z_t* _lf_z;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // width of -2 indicates that it is not a multiport.
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    int _lf_z_width;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Default input (in case it does not get connected)
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_z_t _lf_default__z;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_pitch_t _lf_pitch;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    int _lf_pitch_width;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    _tilt_roll_t _lf_roll;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    int _lf_roll_width;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    reaction_t _lf__reaction_0;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    reaction_t _lf__reaction_1;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    trigger_t _lf__x;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    reaction_t* _lf__x_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    trigger_t _lf__y;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    reaction_t* _lf__y_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    trigger_t _lf__z;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    reaction_t* _lf__z_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _tilt_self_t;
_tilt_self_t* new__tilt();
#endif // _TILT_H
