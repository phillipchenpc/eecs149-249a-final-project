#ifndef _ROBOTBLE_H
#define _ROBOTBLE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_224192895_H
#define TOP_LEVEL_PREAMBLE_224192895_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robotble_tx_char_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robotble_rx_char_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    _robotble_tx_char_t* _lf_tx_char;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    // width of -2 indicates that it is not a multiport.
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    int _lf_tx_char_width;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    // Default input (in case it does not get connected)
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    _robotble_tx_char_t _lf_default__tx_char;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    _robotble_rx_char_t _lf_rx_char;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    int _lf_rx_char_width;
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t _lf__reaction_0;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t _lf__reaction_1;
    #line 43 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t _lf__reaction_2;
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    trigger_t _lf__check_uart;
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t* _lf__check_uart_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    trigger_t _lf__tx_char;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t* _lf__tx_char_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _robotble_self_t;
_robotble_self_t* new__robotble();
#endif // _ROBOTBLE_H
