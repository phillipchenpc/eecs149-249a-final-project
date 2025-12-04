#ifndef _HILLLINEDETECTSOLUTION_MAIN_H
#define _HILLLINEDETECTSOLUTION_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_1133380712_H
#define TOP_LEVEL_PREAMBLE_1133380712_H
#include <ir_sensors.h>
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    #line 16 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    interval_t calibration_time;
    #line 16 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    interval_t sample_period;
    #line 23 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
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
        #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        _line_reflect_t* reflect;
        #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        trigger_t reflect_trigger;
        #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
        reaction_t* reflect_reactions[1];
    } _lf_line;
    int _lf_line_width;
    #line 25 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t _lf__reaction_0;
    #line 31 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t _lf__reaction_1;
    #line 37 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t _lf__reaction_2;
    #line 41 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t _lf__reaction_3;
    #line 45 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t _lf__reaction_4;
    #line 20 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    trigger_t _lf__t;
    #line 20 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t* _lf__t_reactions[1];
    #line 21 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    trigger_t _lf__seconds;
    #line 21 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t* _lf__seconds_reactions[1];
    #line 22 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    trigger_t _lf__end_calibration;
    #line 22 "/home/foobar/final/lingua_franca/src/train/HillLineDetectSolution.lf"
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _hilllinedetectsolution_main_main_self_t;
_hilllinedetectsolution_main_main_self_t* new__hilllinedetectsolution_main();
#endif // _HILLLINEDETECTSOLUTION_MAIN_H
