#include "include/api/api.h"
#include "include/RobotBLE/RobotBLE.h"
#include "_robotble.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotblereaction_function_0(void* instance_args) {
    _robotble_self_t* self = (_robotble_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 22 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    stdio_init_all();
    
    uart_init(uart0, 9600);
    gpio_set_function(28, GPIO_FUNC_UART); // 28 = transmit
    gpio_set_function(29, GPIO_FUNC_UART); // 29 = receieve
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotblereaction_function_1(void* instance_args) {
    _robotble_self_t* self = (_robotble_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robotble_check_uart_t* check_uart = self->_lf_check_uart;
    int check_uart_width = self->_lf_check_uart_width; SUPPRESS_UNUSED_WARNING(check_uart_width);
    _robotble_rx_char_t* rx_char = &self->_lf_rx_char;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    if (uart_is_readable(uart0)) {
        char c = uart_getc(uart0);
        if (c != '0') {
            lf_set(rx_char, c);
        }
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotblereaction_function_2(void* instance_args) {
    _robotble_self_t* self = (_robotble_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robotble_tx_char_t* tx_char = self->_lf_tx_char;
    int tx_char_width = self->_lf_tx_char_width; SUPPRESS_UNUSED_WARNING(tx_char_width);
    #line 39 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    uart_putc(uart0, tx_char->value);
}
#include "include/api/set_undef.h"
_robotble_self_t* new__robotble() {
    _robotble_self_t* self = (_robotble_self_t*)_lf_new_reactor(sizeof(_robotble_self_t));
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    // Set input by default to an always absent default input.
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_check_uart = &self->_lf_default__check_uart;
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    // Set the default source reactor pointer
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_default__check_uart._base.source_reactor = (self_base_t*)self;
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    // Set input by default to an always absent default input.
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_tx_char = &self->_lf_default__tx_char;
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    // Set the default source reactor pointer
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf_default__tx_char._base.source_reactor = (self_base_t*)self;
    #line 21 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_0.number = 0;
    #line 21 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_0.function = _robotblereaction_function_0;
    #line 21 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_0.self = self;
    #line 21 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 21 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 21 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_0.name = "?";
    #line 21 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_1.number = 1;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_1.function = _robotblereaction_function_1;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_1.self = self;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_1.name = "?";
    #line 29 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_2.number = 2;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_2.function = _robotblereaction_function_2;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_2.self = self;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 38 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_2.name = "?";
    #line 38 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__reaction_2.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__check_uart.last = NULL;
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__check_uart.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__check_uart_reactions[0] = &self->_lf__reaction_1;
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__check_uart.reactions = &self->_lf__check_uart_reactions[0];
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__check_uart.number_of_reactions = 1;
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #ifdef FEDERATED
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__check_uart.physical_time_of_arrival = NEVER;
    #line 17 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #endif // FEDERATED
    self->_lf__check_uart.tmplt.type.element_size = sizeof(bool);
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__tx_char.last = NULL;
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__tx_char.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__tx_char_reactions[0] = &self->_lf__reaction_2;
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__tx_char.reactions = &self->_lf__tx_char_reactions[0];
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__tx_char.number_of_reactions = 1;
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #ifdef FEDERATED
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    self->_lf__tx_char.physical_time_of_arrival = NEVER;
    #line 19 "/home/foobar/final/lingua_franca/src/lib/RobotBLE.lf"
    #endif // FEDERATED
    self->_lf__tx_char.tmplt.type.element_size = sizeof(char);
    return self;
}
