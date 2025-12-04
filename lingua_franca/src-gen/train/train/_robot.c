#include "include/api/api.h"
#include "include/train/Robot.h"
#include "_robot.h"
// *********** From the preamble, verbatim:
#line 21 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
  return target / scale * 100; // 100 cm in 1 m
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
    #line 65 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
    #line 72 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(m.left, e.left->value);
    
    // Calculate speed
    // float now = lf_time_logical();
    // float time_elapsed = now - self->prev_time;
    // lf_set(speed, ((e.left->value - self->prev_left) / time_elapsed) / 100 * self->scale); // In m/s unscaled
    
    // self->prev_time = now;
    // self->prev_left = e.left->value;
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
    #line 83 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
    #line 89 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set_mode(DRIVING);
    // self->target_speed_scaled = scale_values_exp(self->target_speed, self->scale);
    // self->target_deccel_scaled = scale_values_exp(self->decceleration, self->scale);
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
    #line 100 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(m.left_speed, self->target_speed_scaled);
    lf_set(m.right_speed, self->target_speed_scaled * self->motor_calibrate);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_5(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 108 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->start_time = lf_time_physical_elapsed();
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_6(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    #line 112 "/home/foobar/final/lingua_franca/src/train/train.lf"
    if (self->target_speed_scaled == 0) {
      // Get new target speed IF speed is not 0
      float curr_time = lf_time_physical_elapsed();
      float new_speed = self->target_deccel_scaled * (curr_time - self->start_time);
    
      // Set speed
      lf_set(m.left_speed, new_speed);
      lf_set(m.right_speed, new_speed * self->motor_calibrate);
    }
}
#include "include/api/set_undef.h"
_robot_self_t* new__robot() {
    _robot_self_t* self = (_robot_self_t*)_lf_new_reactor(sizeof(_robot_self_t));
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_start = &self->_lf_default__start;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__start._base.source_reactor = (self_base_t*)self;
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set input by default to an always absent default input.
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_side_detect = &self->_lf_default__side_detect;
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Set the default source reactor pointer
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_default__side_detect._base.source_reactor = (self_base_t*)self;
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
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.number = 0;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.function = _robotreaction_function_0;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.self = self;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.name = "?";
    #line 64 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.number = 1;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.function = _robotreaction_function_1;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.self = self;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.name = "?";
    #line 71 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.number = 2;
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.function = _robotreaction_function_2;
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.self = self;
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.name = "?";
    #line 82 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.number = 3;
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.function = _robotreaction_function_3;
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.self = self;
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.name = "?";
    #line 88 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[0];
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.number = 4;
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.function = _robotreaction_function_4;
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.self = self;
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.name = "?";
    #line 99 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[1];
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.number = 5;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.function = _robotreaction_function_5;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.self = self;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.name = "?";
    #line 107 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[2];
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.number = 6;
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.function = _robotreaction_function_6;
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.self = self;
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.name = "?";
    #line 111 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.mode = &self->_lf__modes[2];
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.last = NULL;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t_reactions[1] = &self->_lf__reaction_6;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.number_of_reactions = 2;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 58 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_4;
    self->_lf__startup_reactions[1] = &self->_lf__reaction_5;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 2;
    self->_lf__startup.is_timer = false;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.last = NULL;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start_reactions[0] = &self->_lf__reaction_3;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.reactions = &self->_lf__start_reactions[0];
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.number_of_reactions = 1;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__start.physical_time_of_arrival = NEVER;
    #line 46 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__start.tmplt.type.element_size = sizeof(bool);
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__side_detect.last = NULL;
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__side_detect.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 55 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__side_detect.tmplt.type.element_size = sizeof(uint32_t);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 86 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 86 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].name = "CALIBRATING";
    #line 86 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 86 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[0].flags = 0;
    #line 97 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 97 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].name = "DRIVING";
    #line 97 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 97 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[1].flags = 0;
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].name = "STOPPING";
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 105 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__modes[2].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
