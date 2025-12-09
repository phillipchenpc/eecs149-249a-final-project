#ifndef _BLUETOOTH_MODULE_RENAME_MAIN_H
#define _BLUETOOTH_MODULE_RENAME_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_robotble.h"
#ifndef TOP_LEVEL_PREAMBLE_20945625_H
#define TOP_LEVEL_PREAMBLE_20945625_H
#include <string.h>
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
typedef struct {
    struct self_base_t base;
    
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    char* name;
    #line 22 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    int count;
    struct {
        #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        _robotble_check_uart_t check_uart;
        #line 20 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        _robotble_tx_string_t tx_string;
        #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        _robotble_rx_char_t* rx_char;
        #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        trigger_t rx_char_trigger;
        #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        reaction_t* rx_char_reactions[1];
    } _lf_ble;
    int _lf_ble_width;
    struct {
        #line 28 "/home/foobar/final/lingua_franca/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/final/lingua_franca/src/lib/Display.lf"
        _display_line0_t line0;
    } _lf_disp;
    int _lf_disp_width;
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    reaction_t _lf__reaction_0;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    reaction_t _lf__reaction_1;
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    reaction_t _lf__reaction_2;
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    reaction_t _lf__reaction_3;
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    trigger_t _lf__r;
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    reaction_t* _lf__r_reactions[1];
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    trigger_t _lf__t;
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _bluetooth_module_rename_main_main_self_t;
_bluetooth_module_rename_main_main_self_t* new__bluetooth_module_rename_main();
#endif // _BLUETOOTH_MODULE_RENAME_MAIN_H
