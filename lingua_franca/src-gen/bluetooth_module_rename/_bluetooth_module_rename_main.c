#include "include/api/api.h"
#include "include/bluetooth_module_rename/bluetooth_module_rename.h"
#include "_bluetooth_module_rename_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _bluetooth_module_rename_mainreaction_function_0(void* instance_args) {
    _bluetooth_module_rename_main_main_self_t* self = (_bluetooth_module_rename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 28 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    printf("PROGRAM\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bluetooth_module_rename_mainreaction_function_1(void* instance_args) {
    _bluetooth_module_rename_main_main_self_t* self = (_bluetooth_module_rename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct ble {
        _robotble_check_uart_t* check_uart;
    
    } ble;
    ble.check_uart = &(self->_lf_ble.check_uart);
    #line 32 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    // Read
    lf_set(ble.check_uart, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bluetooth_module_rename_mainreaction_function_2(void* instance_args) {
    _bluetooth_module_rename_main_main_self_t* self = (_bluetooth_module_rename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct ble {
        _robotble_tx_string_t* tx_string;
    
    } ble;
    struct disp {
        _display_line1_t* line1;
    
    } disp;
    ble.tx_string = &(self->_lf_ble.tx_string);
    disp.line1 = &(self->_lf_disp.line1);
    #line 37 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    if (self->count < 1) {
        // Send over the next character
        lf_set(ble.tx_string, self->name);
        self->count++;
        printf("TRANSMITTING.\n");
        lf_set(disp.line1, "TXMT");
    } else {
        // printf("DONE.\n");
        lf_set(disp.line1, "DONE");
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bluetooth_module_rename_mainreaction_function_3(void* instance_args) {
    _bluetooth_module_rename_main_main_self_t* self = (_bluetooth_module_rename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct ble {
        _robotble_rx_char_t* rx_char;
    
    } ble;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    ble.rx_char = self->_lf_ble.rx_char;
    disp.line0 = &(self->_lf_disp.line0);
    #line 50 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    // Only print if it isn't the terminating character
    static char buf[17];
    snprintf(buf, 17, "READ: %c", ble.rx_char->value);
    lf_set(disp.line0, buf);
}
#include "include/api/set_undef.h"
_bluetooth_module_rename_main_main_self_t* new__bluetooth_module_rename_main() {
    _bluetooth_module_rename_main_main_self_t* self = (_bluetooth_module_rename_main_main_self_t*)_lf_new_reactor(sizeof(_bluetooth_module_rename_main_main_self_t));
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
    self->_lf_ble.rx_char_reactions[0] = &self->_lf__reaction_3;
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
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_0.number = 0;
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_0.function = _bluetooth_module_rename_mainreaction_function_0;
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_0.self = self;
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_0.name = "?";
    #line 27 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_1.number = 1;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_1.function = _bluetooth_module_rename_mainreaction_function_1;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_1.self = self;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_1.name = "?";
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_2.number = 2;
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_2.function = _bluetooth_module_rename_mainreaction_function_2;
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_2.self = self;
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_2.name = "?";
    #line 36 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_3.number = 3;
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_3.function = _bluetooth_module_rename_mainreaction_function_3;
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_3.self = self;
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_3.name = "?";
    #line 49 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__r.last = NULL;
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__r.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__r_reactions[0] = &self->_lf__reaction_1;
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__r.reactions = &self->_lf__r_reactions[0];
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__r.number_of_reactions = 1;
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #ifdef FEDERATED
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__r.physical_time_of_arrival = NEVER;
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #endif // FEDERATED
    self->_lf__r.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__r.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__t.last = NULL;
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_2;
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #ifdef FEDERATED
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 25 "/home/foobar/final/lingua_franca/src/bluetooth_module_rename.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
