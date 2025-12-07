#ifndef _LED_H
#define _LED_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_913706751_H
#define TOP_LEVEL_PREAMBLE_913706751_H
#include <hardware/gpio.h>
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
} _led_set_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    _led_set_t* _lf_set;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    // width of -2 indicates that it is not a multiport.
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    int _lf_set_width;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    // Default input (in case it does not get connected)
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    _led_set_t _lf_default__set;
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    reaction_t _lf__reaction_0;
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    trigger_t _lf__set;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    reaction_t* _lf__set_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _led_self_t;
_led_self_t* new__led();
#endif // _LED_H
