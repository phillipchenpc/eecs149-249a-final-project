#ifndef _TRAIN_MAIN_H
#define _TRAIN_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_253380088_H
#define TOP_LEVEL_PREAMBLE_253380088_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <ir_sensors.h>
#endif
typedef struct {
    struct self_base_t base;
    #line 126 "/home/foobar/final/lingua_franca/src/train/train.lf"
    interval_t calibration_time;
    #line 126 "/home/foobar/final/lingua_franca/src/train/train.lf"
    interval_t sample_period;
    #line 134 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
        #line 38 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        _line_calibrate_t calibrate;
        #line 39 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        _line_trigger_t trigger;
    } _lf_line;
    int _lf_line_width;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_0;
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_1;
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_2;
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t _lf__reaction_3;
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__t;
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__t_reactions[1];
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__seconds;
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__seconds_reactions[1];
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    trigger_t _lf__end_calibration;
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _train_main_main_self_t;
_train_main_main_self_t* new__train_main();
#endif // _TRAIN_MAIN_H
