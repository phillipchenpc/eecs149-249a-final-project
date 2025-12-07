#ifndef _train_main_H
#define _train_main_H
#ifndef TOP_LEVEL_PREAMBLE_253380088_H
#define TOP_LEVEL_PREAMBLE_253380088_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/final/lingua_franca/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
/*Correspondence: Range: [(33, 2), (33, 25)) -> Range: [(0, 0), (0, 23)) (verbatim=true; src=/home/foobar/final/lingua_franca/src/lib/Line.lf)*/#include <ir_sensors.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct train_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    interval_t calibration_time;
    interval_t sample_period;
    interval_t end_time;
    int count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} train_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} line_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} line_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value[5];

} line_reflect_t;
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
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} robot_start_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value;

} robot_line_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value;

} robot_line_center_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value;

} robot_line_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} robot_stop_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} robot_cont_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} robot_speed_t;
#endif
