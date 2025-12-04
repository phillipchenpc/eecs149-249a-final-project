#include "include/api/api.h"
#include "include/HillClimbSolution/HillClimbSolution.h"
#include "_hillclimbsolution_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _hillclimbsolution_mainreaction_function_0(void* instance_args) {
    _hillclimbsolution_main_main_self_t* self = (_hillclimbsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 188 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(disp.line0, "CALIBRATING");
    lf_set(disp.line1, "Roll robot over");
    lf_set(disp.line2, "light and dark.");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _hillclimbsolution_mainreaction_function_1(void* instance_args) {
    _hillclimbsolution_main_main_self_t* self = (_hillclimbsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line3_t* line3;
    
    } disp;
    disp.line3 = &(self->_lf_disp.line3);
    #line 194 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    static char buf[17];
    snprintf(buf, 17, "time:%8d s", self->count++);
    lf_set(disp.line3, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _hillclimbsolution_mainreaction_function_2(void* instance_args) {
    _hillclimbsolution_main_main_self_t* self = (_hillclimbsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    struct robot {
        _robot_start_t* start;
    
    } robot;
    line.calibrate = &(self->_lf_line.calibrate);
    robot.start = &(self->_lf_robot.start);
    #line 200 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(line.calibrate, false);
    lf_set(robot.start, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _hillclimbsolution_mainreaction_function_3(void* instance_args) {
    _hillclimbsolution_main_main_self_t* self = (_hillclimbsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 205 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(line.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _hillclimbsolution_mainreaction_function_4(void* instance_args) {
    _hillclimbsolution_main_main_self_t* self = (_hillclimbsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
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
    #line 209 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
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
    //   snprintf(buf0, 17, "0:%4d 1:%4d", line.reflect->value[0], line.reflect->value[1]);
    //   snprintf(buf1, 17, "2:%4d 3:%4d", line.reflect->value[2], line.reflect->value[3]);
    //   snprintf(buf2, 17, "4:%4d Line:%d", line.reflect->value[4], on_line);
      snprintf(buf0, 17, "Right: %d", right);
      snprintf(buf1, 17, "Center: %d", center);
      snprintf(buf2, 17, "Left: %d", left);
      lf_set(disp.line0, buf0);
      lf_set(disp.line1, buf1);
      lf_set(disp.line2, buf2);
}
#include "include/api/set_undef.h"
_hillclimbsolution_main_main_self_t* new__hillclimbsolution_main() {
    _hillclimbsolution_main_main_self_t* self = (_hillclimbsolution_main_main_self_t*)_lf_new_reactor(sizeof(_hillclimbsolution_main_main_self_t));
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
    #line 187 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.number = 0;
    #line 187 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.function = _hillclimbsolution_mainreaction_function_0;
    #line 187 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.self = self;
    #line 187 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 187 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 187 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.name = "?";
    #line 187 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 193 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.number = 1;
    #line 193 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.function = _hillclimbsolution_mainreaction_function_1;
    #line 193 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.self = self;
    #line 193 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 193 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 193 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.name = "?";
    #line 193 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 199 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.number = 2;
    #line 199 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.function = _hillclimbsolution_mainreaction_function_2;
    #line 199 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.self = self;
    #line 199 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 199 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 199 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.name = "?";
    #line 199 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 204 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.number = 3;
    #line 204 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.function = _hillclimbsolution_mainreaction_function_3;
    #line 204 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.self = self;
    #line 204 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 204 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 204 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.name = "?";
    #line 204 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 208 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.number = 4;
    #line 208 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.function = _hillclimbsolution_mainreaction_function_4;
    #line 208 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.self = self;
    #line 208 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 208 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 208 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.name = "?";
    #line 208 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.last = NULL;
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_3;
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 182 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__seconds.last = NULL;
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__seconds_reactions[0] = &self->_lf__reaction_1;
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__seconds.reactions = &self->_lf__seconds_reactions[0];
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__seconds.number_of_reactions = 1;
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__seconds.physical_time_of_arrival = NEVER;
    #line 183 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__end_calibration.last = NULL;
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_2;
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__end_calibration.number_of_reactions = 1;
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #line 184 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
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
