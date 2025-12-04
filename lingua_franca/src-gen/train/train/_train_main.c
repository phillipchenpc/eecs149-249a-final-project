#include "include/api/api.h"
#include "include/train/train.h"
#include "_train_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _train_mainreaction_function_0(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(disp.line0, "CALIBRATING");
    lf_set(disp.line1, "Roll robot over");
    lf_set(disp.line2, "light and dark.");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_1(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line3_t* line3;
    
    } disp;
    disp.line3 = &(self->_lf_disp.line3);
    #line 161 "/home/foobar/final/lingua_franca/src/train/train.lf"
    static char buf[17];
    snprintf(buf, 17, "time:%8d s", self->count++);
    lf_set(disp.line3, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_2(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    struct robot {
        _robot_start_t* start;
    
    } robot;
    line.calibrate = &(self->_lf_line.calibrate);
    robot.start = &(self->_lf_robot.start);
    #line 172 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(line.calibrate, false);
    lf_set(robot.start, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_3(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct robot {
        _robot_stop_t* stop;
    
    } robot;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    robot.stop = &(self->_lf_robot.stop);
    disp.line0 = &(self->_lf_disp.line0);
    #line 177 "/home/foobar/final/lingua_franca/src/train/train.lf"
    static char buf[17];
    snprintf(buf, 17, "slowing");
    lf_set(disp.line0, buf);
    lf_set(robot.stop, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_4(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct robot {
        _robot_cont_t* cont;
    
    } robot;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    robot.cont = &(self->_lf_robot.cont);
    disp.line0 = &(self->_lf_disp.line0);
    #line 183 "/home/foobar/final/lingua_franca/src/train/train.lf"
    static char buf[17];
    snprintf(buf, 17, "starting");
    lf_set(disp.line0, buf);
    lf_set(robot.cont, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_5(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 190 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(line.trigger, true);
}
#include "include/api/set_undef.h"
_train_main_main_self_t* new__train_main() {
    _train_main_main_self_t* self = (_train_main_main_self_t*)_lf_new_reactor(sizeof(_train_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_line_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_robot_width = -2;
    #line 154 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.number = 0;
    #line 154 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.function = _train_mainreaction_function_0;
    #line 154 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.self = self;
    #line 154 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 154 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 154 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.name = "?";
    #line 154 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 160 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.number = 1;
    #line 160 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.function = _train_mainreaction_function_1;
    #line 160 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.self = self;
    #line 160 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 160 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 160 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.name = "?";
    #line 160 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 171 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.number = 2;
    #line 171 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.function = _train_mainreaction_function_2;
    #line 171 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.self = self;
    #line 171 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 171 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 171 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.name = "?";
    #line 171 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 176 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.number = 3;
    #line 176 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.function = _train_mainreaction_function_3;
    #line 176 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.self = self;
    #line 176 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 176 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 176 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.name = "?";
    #line 176 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 182 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.number = 4;
    #line 182 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.function = _train_mainreaction_function_4;
    #line 182 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.self = self;
    #line 182 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 182 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 182 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.name = "?";
    #line 182 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 189 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.number = 5;
    #line 189 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.function = _train_mainreaction_function_5;
    #line 189 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.self = self;
    #line 189 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 189 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 189 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.name = "?";
    #line 189 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.mode = NULL;
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.last = NULL;
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_5;
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.last = NULL;
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds_reactions[0] = &self->_lf__reaction_1;
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.reactions = &self->_lf__seconds_reactions[0];
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.number_of_reactions = 1;
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.physical_time_of_arrival = NEVER;
    #line 146 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.last = NULL;
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_2;
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.number_of_reactions = 1;
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #line 147 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end.last = NULL;
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_reactions[0] = &self->_lf__reaction_3;
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end.reactions = &self->_lf__end_reactions[0];
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end.number_of_reactions = 1;
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end.physical_time_of_arrival = NEVER;
    #line 151 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__end.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_again.last = NULL;
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_again.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_again_reactions[0] = &self->_lf__reaction_4;
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_again.reactions = &self->_lf__start_again_reactions[0];
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_again.number_of_reactions = 1;
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_again.physical_time_of_arrival = NEVER;
    #line 152 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__start_again.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__start_again.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}
