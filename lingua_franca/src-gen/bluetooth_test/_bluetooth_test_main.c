#include "include/api/api.h"
#include "include/bluetooth_test/bluetooth_test.h"
#include "_bluetooth_test_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _bluetooth_test_mainreaction_function_0(void* instance_args) {
    _bluetooth_test_main_main_self_t* self = (_bluetooth_test_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct ble {
        _robotble_rx_char_t* rx_char;
    
    } ble;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    ble.rx_char = self->_lf_ble.rx_char;
    disp.line0 = &(self->_lf_disp.line0);
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    static char buf[17];
    sprintf(buf, 17, "%c", ble.rx_char->value);
    lf_set(disp.line0, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bluetooth_test_mainreaction_function_1(void* instance_args) {
    _bluetooth_test_main_main_self_t* self = (_bluetooth_test_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct ble {
        _robotble_tx_char_t* tx_char;
    
    } ble;
    ble.tx_char = &(self->_lf_ble.tx_char);
    #line 60 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    lf_set(ble.tx_char, "H");
}
#include "include/api/set_undef.h"
_bluetooth_test_main_main_self_t* new__bluetooth_test_main() {
    _bluetooth_test_main_main_self_t* self = (_bluetooth_test_main_main_self_t*)_lf_new_reactor(sizeof(_bluetooth_test_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_ble_width = -2;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_ble.rx_char_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_ble.rx_char_reactions[0] = &self->_lf__reaction_0;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_ble.rx_char_trigger.reactions = self->_lf_ble.rx_char_reactions;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_ble.rx_char_trigger.last = NULL;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_ble.rx_char_trigger.number_of_reactions = 1;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_ble.rx_char_trigger.physical_time_of_arrival = NEVER;
    #line 20 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.number = 0;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.function = _bluetooth_test_mainreaction_function_0;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.self = self;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.name = "?";
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 59 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.number = 1;
    #line 59 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.function = _bluetooth_test_mainreaction_function_1;
    #line 59 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.self = self;
    #line 59 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 59 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 59 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.name = "?";
    #line 59 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.last = NULL;
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 53 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
