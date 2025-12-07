#include "include/api/api.h"
#include "include/bluetooth_test/RobotBLE.h"
#include "_robotble.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotblereaction_function_0(void* instance_args) {
    _robotble_self_t* self = (_robotble_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 24 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    stdio_init_all();
    
    uart_init(uart0, 9600);
    gpio_set_function(28, GPIO_FUNC_UART);
    gpio_set_function(29, GPIO_FUNC_UART);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotblereaction_function_1(void* instance_args) {
    _robotble_self_t* self = (_robotble_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robotble_rx_char_t* rx_char = &self->_lf_rx_char;
    #line 32 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    if (uart_is_readable(uart0)) {
        char c = uart_getc(uart0);
        printf("Reading: %c\n", c);
        lf_set(rx_char, c);
    } else {
        printf("Nothing.\n");
        // lf_set(rx_char, '\0');
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotblereaction_function_2(void* instance_args) {
    _robotble_self_t* self = (_robotble_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robotble_tx_char_t* tx_char = self->_lf_tx_char;
    int tx_char_width = self->_lf_tx_char_width; SUPPRESS_UNUSED_WARNING(tx_char_width);
    #line 43 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    uart_puts(uart0, "ECHO: ");
    uart_putc(uart0, tx_char);
    uart_puts(uart0, "\n");
}
#include "include/api/set_undef.h"
_robotble_self_t* new__robotble() {
    _robotble_self_t* self = (_robotble_self_t*)_lf_new_reactor(sizeof(_robotble_self_t));
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    // Set input by default to an always absent default input.
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_tx_char = &self->_lf_default__tx_char;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    // Set the default source reactor pointer
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf_default__tx_char._base.source_reactor = (self_base_t*)self;
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.number = 0;
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.function = _robotblereaction_function_0;
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.self = self;
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.name = "?";
    #line 23 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.number = 1;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.function = _robotblereaction_function_1;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.self = self;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.name = "?";
    #line 31 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 42 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_2.number = 2;
    #line 42 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_2.function = _robotblereaction_function_2;
    #line 42 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_2.self = self;
    #line 42 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 42 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 42 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_2.name = "?";
    #line 42 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__check_uart.last = NULL;
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__check_uart.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__check_uart_reactions[0] = &self->_lf__reaction_1;
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__check_uart.reactions = &self->_lf__check_uart_reactions[0];
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__check_uart.number_of_reactions = 1;
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__check_uart.physical_time_of_arrival = NEVER;
    #line 19 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED
    self->_lf__check_uart.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__check_uart.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__tx_char.last = NULL;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__tx_char.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__tx_char_reactions[0] = &self->_lf__reaction_2;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__tx_char.reactions = &self->_lf__tx_char_reactions[0];
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__tx_char.number_of_reactions = 1;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #ifdef FEDERATED
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    self->_lf__tx_char.physical_time_of_arrival = NEVER;
    #line 21 "/home/foobar/final/lingua_franca/src/bluetooth_test.lf"
    #endif // FEDERATED
    self->_lf__tx_char.tmplt.type.element_size = sizeof(char);
    return self;
}
