#include "include/api/api.h"
#include "include/bluetooth_test/bluetooth_test.h"
#include "_bluetooth_test_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _bluetooth_test_mainreaction_function_0(void* instance_args) {
    _bluetooth_test_main_main_self_t* self = (_bluetooth_test_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    #line 56 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    static char buf[17];
    sprintf(buf, 17, "%c", ble.rx_char->value);
    lf_set(disp.line0, buf);
}
#include "include/api/set_undef.h"
_bluetooth_test_main_main_self_t* new__bluetooth_test_main() {
    _bluetooth_test_main_main_self_t* self = (_bluetooth_test_main_main_self_t*)_lf_new_reactor(sizeof(_bluetooth_test_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.number = 0;
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.function = _bluetooth_test_mainreaction_function_0;
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.self = self;
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.name = "?";
    #line 55 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.last = NULL;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 54 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
