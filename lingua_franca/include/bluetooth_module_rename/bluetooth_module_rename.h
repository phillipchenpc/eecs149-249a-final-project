#ifndef _bluetooth_module_rename_main_H
#define _bluetooth_module_rename_main_H
#ifndef TOP_LEVEL_PREAMBLE_20945625_H
#define TOP_LEVEL_PREAMBLE_20945625_H
/*Correspondence: Range: [(12, 4), (12, 23)) -> Range: [(0, 0), (0, 19)) (verbatim=true; src=/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf)*/#include <string.h>
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/final/lingua_franca/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
/*Correspondence: Range: [(9, 4), (11, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct bluetooth_module_rename_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    char* name;
    int count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} bluetooth_module_rename_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} robotble_check_uart_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;

} robotble_tx_char_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} robotble_tx_string_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;

} robotble_rx_char_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line3_t;
#endif
