#ifndef _BLUETOOTH_TEST_MAIN_H
#define _BLUETOOTH_TEST_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_robotble.h"
#ifndef TOP_LEVEL_PREAMBLE_224192895_H
#define TOP_LEVEL_PREAMBLE_224192895_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    
    
    struct {
        #line 27 "/home/foobar/final/lingua_franca/src/lib/Display.lf"
        _display_line0_t line0;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
        _robotble_rx_char_t* rx_char;
        #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
        trigger_t rx_char_trigger;
        #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
        reaction_t* rx_char_reactions[1];
        #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
        _robotble_tx_char_t tx_char;
    } _lf_ble;
    int _lf_ble_width;
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t _lf__reaction_0;
    #line 60 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t _lf__reaction_1;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    trigger_t _lf__t;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    reaction_t* _lf__t_reactions[1];
} _bluetooth_test_main_main_self_t;
_bluetooth_test_main_main_self_t* new__bluetooth_test_main();
#endif // _BLUETOOTH_TEST_MAIN_H
