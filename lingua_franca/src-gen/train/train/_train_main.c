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
    #line 139 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
    #line 145 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    struct robot {
        _robot_start_t* start;
    
    } robot;
    line.calibrate = &(self->_lf_line.calibrate);
    disp.line0 = &(self->_lf_disp.line0);
    robot.start = &(self->_lf_robot.start);
    #line 156 "/home/foobar/final/lingua_franca/src/train/train.lf"
    static char buf[17];
    snprintf(buf, 17, "IM HERE");
    lf_set(disp.line0, buf);
    
    lf_set(line.calibrate, false);
    lf_set(robot.start, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_3(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 165 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(line.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_4(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    struct robot {
        _robot_side_detect_t* side_detect;
    
    } robot;
    line.reflect = self->_lf_line.reflect;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    robot.side_detect = &(self->_lf_robot.side_detect);
    #line 169 "/home/foobar/final/lingua_franca/src/train/train.lf"
    static char buf0[17];
    static char buf1[17];
    static char buf2[17];
    bool right = line.reflect->value[4] > 800; 
    bool center = line.reflect->value[1] > 800 || line.reflect->value[2] > 800 || line.reflect->value[3] > 800;
    bool left = line.reflect->value[0] > 800;
    if (left && center && right) {
      lf_set(robot.side_detect, 2);
    } else if(left && center) {
      lf_set(robot.side_detect, 1);
    } else if (right && center) {
      lf_set(robot.side_detect, 3);
    } else if (center) {
      lf_set(robot.side_detect, 2);
    } else if (left) {
      lf_set(robot.side_detect, 0);
    } else if (right) {
      lf_set(robot.side_detect, 4);
    } else {
      lf_set(robot.side_detect, 5);
    }
    
    snprintf(buf0, 17, "Right: %d", right);
    snprintf(buf1, 17, "Center: %d", center);
    snprintf(buf2, 17, "Left: %d", left);
    lf_set(disp.line0, buf0);
    lf_set(disp.line1, buf1);
    lf_set(disp.line2, buf2);
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
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_4;
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.reactions = self->_lf_line.reflect_reactions;
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.last = NULL;
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.number_of_reactions = 1;
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    #ifdef FEDERATED
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.physical_time_of_arrival = NEVER;
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Line.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_robot_width = -2;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.number = 0;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.function = _train_mainreaction_function_0;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.self = self;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.name = "?";
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.number = 1;
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.function = _train_mainreaction_function_1;
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.self = self;
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.name = "?";
    #line 144 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.number = 2;
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.function = _train_mainreaction_function_2;
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.self = self;
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.name = "?";
    #line 155 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.number = 3;
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.function = _train_mainreaction_function_3;
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.self = self;
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.name = "?";
    #line 164 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 168 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.number = 4;
    #line 168 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.function = _train_mainreaction_function_4;
    #line 168 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.self = self;
    #line 168 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 168 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 168 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.name = "?";
    #line 168 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.last = NULL;
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_3;
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 131 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.last = NULL;
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds_reactions[0] = &self->_lf__reaction_1;
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.reactions = &self->_lf__seconds_reactions[0];
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.number_of_reactions = 1;
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.physical_time_of_arrival = NEVER;
    #line 132 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.last = NULL;
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_2;
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.number_of_reactions = 1;
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #line 133 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
