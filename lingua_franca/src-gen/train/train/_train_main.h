#ifndef _TRAIN_MAIN_H
#define _TRAIN_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_robotble.h"
#include "_robot.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_2068499906_H
#define TOP_LEVEL_PREAMBLE_2068499906_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <ir_sensors.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
typedef struct {
    struct self_base_t base;
    #line 212 "/home/foobar/final/lingua_franca/src/train/train.lf"
    interval_t calibration_time;
    #line 212 "/home/foobar/final/lingua_franca/src/train/train.lf"
    interval_t sample_period;
    #line 212 "/home/foobar/final/lingua_franca/src/train/train.lf"
    interval_t end_time;
    #line 221 "/home/foobar/final/lingua_franca/src/train/train.lf"
    int count;
    struct {
        #line 27 "/home/foobar/final/lingua_franca/src/lib/Display.lf"
        _display_line0_t line0;
        #line 28 "/home/foobar/final/lingua_franca/src/lib/Display.lf"
        _display_line1_t line1;
        #line 29 "/home/foobar/final/lingua_franca/src/lib/Display.lf"
        _display_line2_t line2;
        #line 30 "/home/foobar/final/lingua_franca/src/lib/Display.lf"
        _display_line3_t line3;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
        _robot_speed_t* speed;
        #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
        trigger_t speed_trigger;
        #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
        reaction_t* speed_reactions[1];
        #line 48 "/home/foobar/final/lingua_franca/src/train/train.lf"
        _robot_start_t start;
        #line 74 "/home/foobar/final/lingua_franca/src/train/train.lf"
        _robot_stop_t stop;
        #line 76 "/home/foobar/final/lingua_franca/src/train/train.lf"
        _robot_cont_t cont;
        #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
        _robot_line_left_t line_left;
        #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
        _robot_line_center_t line_center;
        #line 59 "/home/foobar/final/lingua_franca/src/train/train.lf"
        _robot_line_right_t line_right;
    } _lf_robot;
    int _lf_robot_width;
    struct {
        #line 38 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        _line_calibrate_t calibrate;
        #line 39 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        _line_trigger_t trigger;
        #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        _line_reflect_t* reflect;
        #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        trigger_t reflect_trigger;
        #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        reaction_t* reflect_reactions[1];
    } _lf_line;
    int _lf_line_width;
    struct {
        #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        _robotble_check_uart_t check_uart;
        #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        _robotble_rx_char_t* rx_char;
        #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        trigger_t rx_char_trigger;
        #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
        reaction_t* rx_char_reactions[1];
    } _lf_ble;
    int _lf_ble_width;
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_0;
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_1;
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_2;
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_3;
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_4;
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_5;
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_6;
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__t;
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__t_reactions[1];
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__seconds;
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__seconds_reactions[1];
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__end_calibration;
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _train_main_main_self_t;
_train_main_main_self_t* new__train_main();
#endif // _TRAIN_MAIN_H
