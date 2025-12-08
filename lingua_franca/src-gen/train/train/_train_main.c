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
    #line 228 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(disp.line0, "CALIBRATING");
    lf_set(disp.line1, "Roll robot over");
    lf_set(disp.line2, "light and dark.");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_1(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 234 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Just to keep track of time
    self->count++;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_2(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct robot {
        _robot_speed_t* speed;
    
    } robot;
    struct disp {
        _display_line3_t* line3;
    
    } disp;
    robot.speed = self->_lf_robot.speed;
    disp.line3 = &(self->_lf_disp.line3);
    #line 239 "/home/foobar/final/lingua_franca/src/train/train.lf"
    static char buf[17];
    snprintf(buf, 17, "V:%.2fm/s,T:%.2ds", robot.speed->value, self->count);
    lf_set(disp.line3, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_3(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    struct robot {
        _robot_start_t* start;
    
    } robot;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    line.calibrate = &(self->_lf_line.calibrate);
    robot.start = &(self->_lf_robot.start);
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 245 "/home/foobar/final/lingua_franca/src/train/train.lf"
    // Clearing screen
    lf_set(disp.line0, "");
    lf_set(disp.line1, "");
    lf_set(disp.line2, "");
    
    lf_set(line.calibrate, false);
    lf_set(robot.start, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_4(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    struct ble {
        _robotble_check_uart_t* check_uart;
    
    } ble;
    line.trigger = &(self->_lf_line.trigger);
    ble.check_uart = &(self->_lf_ble.check_uart);
    #line 269 "/home/foobar/final/lingua_franca/src/train/train.lf"
    lf_set(line.trigger, true);
    lf_set(ble.check_uart, true); // Check for messages
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_5(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct ble {
        _robotble_rx_char_t* rx_char;
    
    } ble;
    struct robot {
        _robot_stop_t* stop;
    _robot_cont_t* cont;
    
    } robot;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    ble.rx_char = self->_lf_ble.rx_char;
    robot.stop = &(self->_lf_robot.stop);
    robot.cont = &(self->_lf_robot.cont);
    disp.line0 = &(self->_lf_disp.line0);
    #line 274 "/home/foobar/final/lingua_franca/src/train/train.lf"
    char c = ble.rx_char->value;
    static char buf[17];
    if (c == '0') {
      // 0 == stop
      lf_set(robot.stop, true);
      snprintf(buf, 17, "Stopping.");
    } else if (c == '1') {
      // 1 == start
      lf_set(robot.cont, true);
      snprintf(buf, 17, "Driving.");
    }
    
    // Printing
    lf_set(disp.line0, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _train_mainreaction_function_6(void* instance_args) {
    _train_main_main_self_t* self = (_train_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct disp {
        _display_line1_t* line1;
    
    } disp;
    struct robot {
        _robot_line_left_t* line_left;
    _robot_line_center_t* line_center;
    _robot_line_right_t* line_right;
    
    } robot;
    line.reflect = self->_lf_line.reflect;
    disp.line1 = &(self->_lf_disp.line1);
    robot.line_left = &(self->_lf_robot.line_left);
    robot.line_center = &(self->_lf_robot.line_center);
    robot.line_right = &(self->_lf_robot.line_right);
    #line 291 "/home/foobar/final/lingua_franca/src/train/train.lf"
    static char buf1[17];
    // Just seeing if it's detecting or not
    bool right = line.reflect->value[3] > 500;
    bool center = line.reflect->value[2] > 500;
    bool left = line.reflect->value[1] > 500;
    snprintf(buf1, 17, "R:%d,C:%d,L:%d", right, center, left);
    lf_set(disp.line1, buf1);
    printf("READ\n");
    
    // Larger = darker
    lf_set(robot.line_right, line.reflect->value[3]); 
    lf_set(robot.line_center, line.reflect->value[2]); 
    lf_set(robot.line_left, line.reflect->value[1]);
}
#include "include/api/set_undef.h"
_train_main_main_self_t* new__train_main() {
    _train_main_main_self_t* self = (_train_main_main_self_t*)_lf_new_reactor(sizeof(_train_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_robot_width = -2;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_robot.speed_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_robot.speed_reactions[0] = &self->_lf__reaction_2;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_robot.speed_trigger.reactions = self->_lf_robot.speed_reactions;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_robot.speed_trigger.last = NULL;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_robot.speed_trigger.number_of_reactions = 1;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf_robot.speed_trigger.physical_time_of_arrival = NEVER;
    #line 52 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
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
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_6;
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
    self->_lf_ble_width = -2;
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_ble.rx_char_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_ble.rx_char_reactions[0] = &self->_lf__reaction_5;
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_ble.rx_char_trigger.reactions = self->_lf_ble.rx_char_reactions;
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_ble.rx_char_trigger.last = NULL;
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_ble.rx_char_trigger.number_of_reactions = 1;
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #ifdef FEDERATED
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_ble.rx_char_trigger.physical_time_of_arrival = NEVER;
    #line 18 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #endif // FEDERATED
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.number = 0;
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.function = _train_mainreaction_function_0;
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.self = self;
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.name = "?";
    #line 227 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.number = 1;
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.function = _train_mainreaction_function_1;
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.self = self;
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.name = "?";
    #line 233 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.number = 2;
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.function = _train_mainreaction_function_2;
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.self = self;
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.name = "?";
    #line 238 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.number = 3;
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.function = _train_mainreaction_function_3;
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.self = self;
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.name = "?";
    #line 244 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.number = 4;
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.function = _train_mainreaction_function_4;
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.self = self;
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.name = "?";
    #line 268 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.number = 5;
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.function = _train_mainreaction_function_5;
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.self = self;
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.name = "?";
    #line 273 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_5.mode = NULL;
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.number = 6;
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.function = _train_mainreaction_function_6;
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.self = self;
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.name = "?";
    #line 290 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__reaction_6.mode = NULL;
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.last = NULL;
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_4;
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 218 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.last = NULL;
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds_reactions[0] = &self->_lf__reaction_1;
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.reactions = &self->_lf__seconds_reactions[0];
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.number_of_reactions = 1;
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__seconds.physical_time_of_arrival = NEVER;
    #line 219 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.last = NULL;
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_3;
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.number_of_reactions = 1;
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    #ifdef FEDERATED
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #line 220 "/home/foobar/final/lingua_franca/src/train/train.lf"
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
