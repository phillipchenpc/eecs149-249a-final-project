#include "include/api/api.h"
#include "include/HillClimbSolution/Robot.h"
#include "_robot.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotreaction_function_0(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct g {
        _gyroangle_trigger_t* trigger;
    
    } g;
    struct e {
        _encoders_trigger_t* trigger;
    
    } e;
    struct a {
        _accelerometer_trigger_t* trigger;
    
    } a;
    g.trigger = &(self->_lf_g.trigger);
    e.trigger = &(self->_lf_e.trigger);
    a.trigger = &(self->_lf_a.trigger);
    #line 43 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(g.trigger, true);
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
    #line 50 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(m.left, e.left->value);
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
    #line 53 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(m.right, e.right->value);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_3(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct a {
        _accelerometer_x_t* x;
    _accelerometer_y_t* y;
    _accelerometer_z_t* z;
    
    } a;
    struct tilt {
        _tilt_x_t* x;
    _tilt_y_t* y;
    _tilt_z_t* z;
    
    } tilt;
    a.x = self->_lf_a.x;
    a.y = self->_lf_a.y;
    a.z = self->_lf_a.z;
    tilt.x = &(self->_lf_tilt.x);
    tilt.y = &(self->_lf_tilt.y);
    tilt.z = &(self->_lf_tilt.z);
    #line 58 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(tilt.x, a.x->value);
    lf_set(tilt.y, a.y->value);
    lf_set(tilt.z, a.z->value);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_4(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct tilt {
        _tilt_roll_t* roll;
    _tilt_pitch_t* pitch;
    
    } tilt;
    tilt.roll = self->_lf_tilt.roll;
    tilt.pitch = self->_lf_tilt.pitch;
    #line 64 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    printf("Pitch: %f, Roll: %f \n", tilt.pitch->value, tilt.roll->value);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_5(void* instance_args) {
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
    #line 71 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set_mode(DRIVING);
    lf_set(m.left_speed, self->speed);
    lf_set(m.right_speed, self->speed * self->motor_calibrate);
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
    #line 80 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    lf_set(m.left_speed, self->speed);
    lf_set(m.right_speed, self->speed * self->motor_calibrate);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_7(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct g {
        _gyroangle_z_t* z;
    
    } g;
    g.z = self->_lf_g.z;
    #line 86 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->last_angle = g.z->value;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_8(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct tilt {
        _tilt_roll_t* roll;
    
    } tilt;
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    tilt.roll = self->_lf_tilt.roll;
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    #line 91 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    int direction = self->direction_up ? 1 : -1;
    float gain = 0.005;
    float left_feedback = -tilt.roll->value * gain * direction;
    float right_feedback = tilt.roll->value * gain * direction;
    // Turn left
    lf_set(m.left_speed, (self->speed + left_feedback));
    lf_set(m.right_speed, (self->speed + right_feedback) * self->motor_calibrate);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_9(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct tilt {
        _tilt_pitch_t* pitch;
    
    } tilt;
    struct g {
        _gyroangle_z_t* z;
    
    } g;
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    tilt.pitch = self->_lf_tilt.pitch;
    g.z = self->_lf_g.z;
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    reactor_mode_t* MANEUVER = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_MANEUVER_change_type = reset_transition;
    #line 102 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // Check which direction we're going
    if (self->direction_up && abs(tilt.pitch->value) < self->pitch_max) {
      // Change directions
      self->direction_up = !self->direction_up;
      // Turn 180 degrees
      self->last_angle = g.z->value;
      // Start robot turning
      lf_set(m.left_speed, -self->speed);
      lf_set(m.right_speed, self->speed * self->motor_calibrate);
      // Switch over to MANEUVER with correct mode
      self->last_detect = 2; // Turn 180 degrees
      lf_set_mode(MANEUVER);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_10(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    _robot_side_detect_t* side_detect = self->_lf_side_detect;
    int side_detect_width = self->_lf_side_detect_width; SUPPRESS_UNUSED_WARNING(side_detect_width);
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    reactor_mode_t* BACKUP = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_BACKUP_change_type = reset_transition;
    #line 118 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    if (side_detect->value != 5){
      // Start backing up
      lf_set(m.left_speed, -self->speed);
      lf_set(m.right_speed, -self->speed * self->motor_calibrate);
    
      self->last_detect = side_detect->value; // Make sure this value doesn't change as we maneuver
    
      lf_set_mode(BACKUP);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_11(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    _robot_side_detect_t* side_detect = self->_lf_side_detect;
    int side_detect_width = self->_lf_side_detect_width; SUPPRESS_UNUSED_WARNING(side_detect_width);
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    reactor_mode_t* MANEUVER = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_MANEUVER_change_type = reset_transition;
    #line 143 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    if (side_detect->value == 5) {
      // Start turn only if we don't detect anything anymore
      if (self->last_detect <= 2) {
        // Turning right
        lf_set(m.left_speed, self->speed);
        lf_set(m.right_speed, -self->speed * self->motor_calibrate);
      } else {
        // Turning Left
        lf_set(m.left_speed, -self->speed);
        lf_set(m.right_speed, self->speed * self->motor_calibrate);
      }
    
      // Change mode
      lf_set_mode(MANEUVER);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_12(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct g {
        _gyroangle_z_t* z;
    
    } g;
    struct m {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } m;
    g.z = self->_lf_g.z;
    m.left_speed = &(self->_lf_m.left_speed);
    m.right_speed = &(self->_lf_m.right_speed);
    reactor_mode_t* DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    #line 163 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    float turned_angle = abs(g.z->value - self->last_angle);
    
    int target = self->turning_angles[self->last_detect];
    if (turned_angle >= target) {
      // Done executing maneuver
      lf_set_mode(DRIVING);
      lf_set(m.left_speed, self->speed);
      lf_set(m.right_speed, self->speed * self->motor_calibrate);
    }
}
#include "include/api/set_undef.h"
_robot_self_t* new__robot() {
    _robot_self_t* self = (_robot_self_t*)_lf_new_reactor(sizeof(_robot_self_t));
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // Set input by default to an always absent default input.
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf_start = &self->_lf_default__start;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // Set the default source reactor pointer
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf_default__start._base.source_reactor = (self_base_t*)self;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // Set input by default to an always absent default input.
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf_side_detect = &self->_lf_default__side_detect;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    // Set the default source reactor pointer
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf_default__side_detect._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_g_width = -2;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_reactions[0] = &self->_lf__reaction_7;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_reactions[1] = &self->_lf__reaction_9;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_reactions[2] = &self->_lf__reaction_12;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_trigger.reactions = self->_lf_g.z_reactions;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_trigger.last = NULL;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_trigger.number_of_reactions = 3;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_g.z_trigger.physical_time_of_arrival = NEVER;
    #line 122 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED
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
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.x_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.x_reactions[0] = &self->_lf__reaction_3;
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.x_trigger.reactions = self->_lf_a.x_reactions;
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.x_trigger.last = NULL;
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.x_trigger.number_of_reactions = 1;
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.x_trigger.physical_time_of_arrival = NEVER;
    #line 37 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.y_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.y_reactions[0] = &self->_lf__reaction_3;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.y_trigger.reactions = self->_lf_a.y_reactions;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.y_trigger.last = NULL;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.y_trigger.number_of_reactions = 1;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.y_trigger.physical_time_of_arrival = NEVER;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.z_reactions[0] = &self->_lf__reaction_3;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.z_trigger.reactions = self->_lf_a.z_reactions;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.z_trigger.last = NULL;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.z_trigger.number_of_reactions = 1;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    self->_lf_a.z_trigger.physical_time_of_arrival = NEVER;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/IMU.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_m_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_tilt_width = -2;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.roll_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.roll_reactions[0] = &self->_lf__reaction_4;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.roll_reactions[1] = &self->_lf__reaction_8;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.roll_trigger.reactions = self->_lf_tilt.roll_reactions;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.roll_trigger.last = NULL;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.roll_trigger.number_of_reactions = 2;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.roll_trigger.physical_time_of_arrival = NEVER;
    #line 32 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.pitch_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.pitch_reactions[0] = &self->_lf__reaction_4;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.pitch_reactions[1] = &self->_lf__reaction_9;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.pitch_trigger.reactions = self->_lf_tilt.pitch_reactions;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.pitch_trigger.last = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.pitch_trigger.number_of_reactions = 2;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_tilt.pitch_trigger.physical_time_of_arrival = NEVER;
    #line 31 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.number = 0;
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.function = _robotreaction_function_0;
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.self = self;
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.name = "?";
    #line 42 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.number = 1;
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.function = _robotreaction_function_1;
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.self = self;
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.name = "?";
    #line 49 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.number = 2;
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.function = _robotreaction_function_2;
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.self = self;
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.name = "?";
    #line 52 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.number = 3;
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.function = _robotreaction_function_3;
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.self = self;
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.name = "?";
    #line 57 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.number = 4;
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.function = _robotreaction_function_4;
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.self = self;
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.name = "?";
    #line 63 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_5.number = 5;
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_5.function = _robotreaction_function_5;
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_5.self = self;
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_5.name = "?";
    #line 70 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[0];
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_6.number = 6;
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_6.function = _robotreaction_function_6;
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_6.self = self;
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_6.name = "?";
    #line 79 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_6.mode = &self->_lf__modes[1];
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_7.number = 7;
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_7.function = _robotreaction_function_7;
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_7.self = self;
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_7.deadline_violation_handler = NULL;
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_7.STP_handler = NULL;
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_7.name = "?";
    #line 85 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_7.mode = &self->_lf__modes[1];
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_8.number = 8;
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_8.function = _robotreaction_function_8;
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_8.self = self;
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_8.deadline_violation_handler = NULL;
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_8.STP_handler = NULL;
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_8.name = "?";
    #line 90 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_8.mode = &self->_lf__modes[1];
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_9.number = 9;
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_9.function = _robotreaction_function_9;
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_9.self = self;
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_9.deadline_violation_handler = NULL;
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_9.STP_handler = NULL;
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_9.name = "?";
    #line 101 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_9.mode = &self->_lf__modes[1];
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_10.number = 10;
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_10.function = _robotreaction_function_10;
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_10.self = self;
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_10.deadline_violation_handler = NULL;
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_10.STP_handler = NULL;
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_10.name = "?";
    #line 117 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_10.mode = &self->_lf__modes[1];
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_11.number = 11;
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_11.function = _robotreaction_function_11;
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_11.self = self;
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_11.deadline_violation_handler = NULL;
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_11.STP_handler = NULL;
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_11.name = "?";
    #line 142 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_11.mode = &self->_lf__modes[2];
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_12.number = 12;
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_12.function = _robotreaction_function_12;
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_12.self = self;
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_12.deadline_violation_handler = NULL;
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_12.STP_handler = NULL;
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_12.name = "?";
    #line 162 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__reaction_12.mode = &self->_lf__modes[3];
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.last = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 31 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_6;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__start.last = NULL;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__start.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__start_reactions[0] = &self->_lf__reaction_5;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__start.reactions = &self->_lf__start_reactions[0];
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__start.number_of_reactions = 1;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__start.physical_time_of_arrival = NEVER;
    #line 20 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED
    self->_lf__start.tmplt.type.element_size = sizeof(bool);
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__side_detect.last = NULL;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__side_detect.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__side_detect_reactions[0] = &self->_lf__reaction_10;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__side_detect_reactions[1] = &self->_lf__reaction_11;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__side_detect.reactions = &self->_lf__side_detect_reactions[0];
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__side_detect.number_of_reactions = 2;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #ifdef FEDERATED
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__side_detect.physical_time_of_arrival = NEVER;
    #line 25 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    #endif // FEDERATED
    self->_lf__side_detect.tmplt.type.element_size = sizeof(uint32_t);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 68 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 68 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[0].name = "CALIBRATING";
    #line 68 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 68 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[0].flags = 0;
    #line 77 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 77 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[1].name = "DRIVING";
    #line 77 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 77 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[1].flags = 0;
    #line 141 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 141 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[2].name = "BACKUP";
    #line 141 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 141 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[2].flags = 0;
    #line 161 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[3].state = &_lf_self_base->_lf__mode_state;
    #line 161 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[3].name = "MANEUVER";
    #line 161 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[3].deactivation_time = 0;
    #line 161 "/home/foobar/final/lingua_franca/src/HillClimbSolution.lf"
    self->_lf__modes[3].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
