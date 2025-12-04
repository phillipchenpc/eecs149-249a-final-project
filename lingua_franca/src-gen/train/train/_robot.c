#include "include/api/api.h"
#include "include/train/Robot.h"
#include "_robot.h"
// *********** From the preamble, verbatim:
#line 21 "/home/foobar/final/lingua_franca/src/train/train.lf"
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV

float scale_values_exp(float target, float scale) {
  /**
  * Scales the target value from m to our experiment's scale
  * 
  * Params:
  *   target: The real value in m
  *   scale : the number of meters one cm will represent in our experiment
  */
  return target / scale / 100; // 100 cm in 1 m
}

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotreaction_function_0(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct e {
        _encoders_trigger_t* trigger;
    
    } e;
    struct a {
        _accelerometer_trigger_t* trigger;
    
    } a;
    e.trigger = &(self->_lf_e.trigger);
    a.trigger = &(self->_lf_a.trigger);
    #line 73 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(e.trigger, true);
    lf_set(a.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_1(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct e {
        _encoders_left_t* left;
    
    } e;
    struct m {
        _motorswithfeedback_left_t* left;
    
    } m;
    e.left = self->_lf_e.left;
    m.left = &(self->_lf_m.left);
    _robot_speed_t* speed = &self->_lf_speed;
    #line 80 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(m.left, e.left->value);
    
    // Calculate speed
    float now = lf_time_logical_elapsed() / pow(10, 8); // Time in seconds
    float time_elapsed = now - self->prev_time;
    lf_set(speed, ((e.left->value - self->prev_left) / time_elapsed) * 100 * self->scale); // In m/s unscaled
    
    self->prev_time = now;
    self->prev_left = e.left->value;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_2(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct e {
        _encoders_right_t* right;
    
    } e;
    struct m {
        _motorswithfeedback_right_t* right;
    
    } m;
    e.right = self->_lf_e.right;
    m.right = &(self->_lf_m.right);
    #line 91 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(m.right, e.right->value);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_3(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    _robot_start_t* start = self->_lf_start;
    int start_width = self->_lf_start_width; SUPPRESS_UNUSED_WARNING(start_width);
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    reactor_mode_t* DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    #line 97 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set_mode(DRIVING);
    self->target_speed_scaled = scale_values_exp(self->target_speed, self->scale);
    self->target_deccel_scaled = scale_values_exp(self->decceleration, self->scale);
    lf_set(m.left_speed, self->target_speed_scaled);
    lf_set(m.right_speed, self->target_speed_scaled * self->motor_calibrate);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_4(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    #line 108 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(m.left_speed, self->target_speed_scaled);
    lf_set(m.right_speed, self->target_speed_scaled * self->motor_calibrate);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_5(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robot_line_left_t* line_left = self->_lf_line_left;
    int line_left_width = self->_lf_line_left_width; SUPPRESS_UNUSED_WARNING(line_left_width);
    _robot_line_center_t* line_center = self->_lf_line_center;
    int line_center_width = self->_lf_line_center_width; SUPPRESS_UNUSED_WARNING(line_center_width);
    _robot_line_right_t* line_right = self->_lf_line_right;
    int line_right_width = self->_lf_line_right_width; SUPPRESS_UNUSED_WARNING(line_right_width);
    #line 114 "/home/foobar/final/lingua_franca/src/train/train.lf"
    printf("L:%f,C:%f,R:%f\n", line_left, line_center, line_right);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_6(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robot_stop_t* stop = self->_lf_stop;
    int stop_width = self->_lf_stop_width; SUPPRESS_UNUSED_WARNING(stop_width);
    reactor_mode_t* STOPPING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_STOPPING_change_type = reset_transition;
    #line 119 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set_mode(STOPPING);
    self->start_time = lf_time_logical_elapsed() / (pow(10, 9));
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_7(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    #line 128 "/home/foobar/final/lingua_franca/src/train/train.lf"
    float curr_time = lf_time_logical_elapsed() / (pow(10, 9));
    // v - at
    float new_speed = self->target_speed_scaled - self->target_deccel_scaled * (curr_time - self->start_time);
    if (new_speed > 0) {
      // Set new target speed IF speed is not 0
      lf_set(m.left_speed, new_speed);
      lf_set(m.right_speed, new_speed * self->motor_calibrate);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_8(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    _robot_cont_t* cont = self->_lf_cont;
    int cont_width = self->_lf_cont_width; SUPPRESS_UNUSED_WARNING(cont_width);
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    reactor_mode_t* DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    #line 139 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set_mode(DRIVING);
    lf_set(m.left_speed, self->target_speed_scaled);
    lf_set(m.right_speed, self->target_speed_scaled * self->motor_calibrate);
}
#include "include/api/set_undef.h"
_robot_self_t* new__robot() {
    _robot_self_t* self = (_robot_self_t*)_lf_new_reactor(sizeof(_robot_self_t));
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_start = &self->_lf_default__start;
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__start._base.source_reactor = (self_base_t*)self;
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_line_left = &self->_lf_default__line_left;
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__line_left._base.source_reactor = (self_base_t*)self;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_line_center = &self->_lf_default__line_center;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__line_center._base.source_reactor = (self_base_t*)self;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_line_right = &self->_lf_default__line_right;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__line_right._base.source_reactor = (self_base_t*)self;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_stop = &self->_lf_default__stop;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__stop._base.source_reactor = (self_base_t*)self;
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_cont = &self->_lf_default__cont;
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__cont._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_e_width = -2;
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.left_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.left_reactions[0] = &self->_lf__reaction_1;
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.left_trigger.reactions = self->_lf_e.left_reactions;
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.left_trigger.last = NULL;
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.left_trigger.number_of_reactions = 1;
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #ifdef FEDERATED
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.left_trigger.physical_time_of_arrival = NEVER;
    #line 33 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #endif // FEDERATED
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.right_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.right_reactions[0] = &self->_lf__reaction_2;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.right_trigger.reactions = self->_lf_e.right_reactions;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.right_trigger.last = NULL;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.right_trigger.number_of_reactions = 1;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #ifdef FEDERATED
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    self->_lf_e.right_trigger.physical_time_of_arrival = NEVER;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Encoders.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_a_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_m_width = -2;
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.number = 0;
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.function = _robotreaction_function_0;
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.self = self;
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.name = "?";
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 79 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.number = 1;
    #line 79 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.function = _robotreaction_function_1;
    #line 79 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.self = self;
    #line 79 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 79 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 79 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.name = "?";
    #line 79 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 90 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.number = 2;
    #line 90 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.function = _robotreaction_function_2;
    #line 90 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.self = self;
    #line 90 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 90 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 90 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.name = "?";
    #line 90 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 96 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.number = 3;
    #line 96 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.function = _robotreaction_function_3;
    #line 96 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.self = self;
    #line 96 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 96 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 96 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.name = "?";
    #line 96 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[0];
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.number = 4;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.function = _robotreaction_function_4;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.self = self;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.name = "?";
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[1];
    #line 113 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.number = 5;
    #line 113 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.function = _robotreaction_function_5;
    #line 113 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.self = self;
    #line 113 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 113 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 113 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.name = "?";
    #line 113 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[1];
    #line 118 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.number = 6;
    #line 118 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.function = _robotreaction_function_6;
    #line 118 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.self = self;
    #line 118 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 118 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 118 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.name = "?";
    #line 118 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.mode = &self->_lf__modes[1];
    #line 127 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_7.number = 7;
    #line 127 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_7.function = _robotreaction_function_7;
    #line 127 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_7.self = self;
    #line 127 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_7.deadline_violation_handler = NULL;
    #line 127 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_7.STP_handler = NULL;
    #line 127 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_7.name = "?";
    #line 127 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_7.mode = &self->_lf__modes[2];
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_8.number = 8;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_8.function = _robotreaction_function_8;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_8.self = self;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_8.deadline_violation_handler = NULL;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_8.STP_handler = NULL;
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_8.name = "?";
    #line 138 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_8.mode = &self->_lf__modes[2];
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.last = NULL;
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 61 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__update.last = NULL;
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__update_reactions[0] = &self->_lf__reaction_7;
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__update.reactions = &self->_lf__update_reactions[0];
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__update.number_of_reactions = 1;
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__update.physical_time_of_arrival = NEVER;
    #line 125 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__update.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_4;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.last = NULL;
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_reactions[0] = &self->_lf__reaction_3;
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.reactions = &self->_lf__start_reactions[0];
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.number_of_reactions = 1;
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.physical_time_of_arrival = NEVER;
    #line 47 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__start.tmplt.type.element_size = sizeof(bool);
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_left.last = NULL;
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_left.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_left_reactions[0] = &self->_lf__reaction_5;
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_left.reactions = &self->_lf__line_left_reactions[0];
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_left.number_of_reactions = 1;
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_left.physical_time_of_arrival = NEVER;
    #line 56 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__line_left.tmplt.type.element_size = sizeof(uint32_t);
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_center.last = NULL;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_center.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_center_reactions[0] = &self->_lf__reaction_5;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_center.reactions = &self->_lf__line_center_reactions[0];
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_center.number_of_reactions = 1;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_center.physical_time_of_arrival = NEVER;
    #line 57 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__line_center.tmplt.type.element_size = sizeof(uint32_t);
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_right.last = NULL;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_right.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_right_reactions[0] = &self->_lf__reaction_5;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_right.reactions = &self->_lf__line_right_reactions[0];
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_right.number_of_reactions = 1;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__line_right.physical_time_of_arrival = NEVER;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__line_right.tmplt.type.element_size = sizeof(uint32_t);
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__stop.last = NULL;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__stop.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__stop_reactions[0] = &self->_lf__reaction_6;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__stop.reactions = &self->_lf__stop_reactions[0];
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__stop.number_of_reactions = 1;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__stop.physical_time_of_arrival = NEVER;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__stop.tmplt.type.element_size = sizeof(bool);
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__cont.last = NULL;
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__cont.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__cont_reactions[0] = &self->_lf__reaction_8;
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__cont.reactions = &self->_lf__cont_reactions[0];
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__cont.number_of_reactions = 1;
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__cont.physical_time_of_arrival = NEVER;
    #line 66 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__cont.tmplt.type.element_size = sizeof(bool);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 94 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 94 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].name = "CALIBRATING";
    #line 94 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 94 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].flags = 0;
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].name = "DRIVING";
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].flags = 0;
    #line 124 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 124 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].name = "STOPPING";
    #line 124 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 124 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
