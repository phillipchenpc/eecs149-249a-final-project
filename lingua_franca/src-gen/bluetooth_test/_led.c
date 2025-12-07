#include "include/api/api.h"
#include "include/LED/LED.h"
#include "_led.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _ledreaction_function_0(void* instance_args) {
    _led_self_t* self = (_led_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 16 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _ledreaction_function_1(void* instance_args) {
    _led_self_t* self = (_led_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _led_set_t* set = self->_lf_set;
    int set_width = self->_lf_set_width; SUPPRESS_UNUSED_WARNING(set_width);
    #line 21 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    printf("LED State: %b\n", set->value);
    gpio_put(PICO_DEFAULT_LED_PIN, set->value);
}
#include "include/api/set_undef.h"
_led_self_t* new__led() {
    _led_self_t* self = (_led_self_t*)_lf_new_reactor(sizeof(_led_self_t));
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    // Set input by default to an always absent default input.
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf_set = &self->_lf_default__set;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    // Set the default source reactor pointer
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf_default__set._base.source_reactor = (self_base_t*)self;
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_0.number = 0;
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_0.function = _ledreaction_function_0;
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_0.self = self;
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_0.name = "?";
    #line 15 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_1.number = 1;
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_1.function = _ledreaction_function_1;
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_1.self = self;
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_1.name = "?";
    #line 20 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__set.last = NULL;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__set.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__set_reactions[0] = &self->_lf__reaction_1;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__set.reactions = &self->_lf__set_reactions[0];
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__set.number_of_reactions = 1;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    #ifdef FEDERATED
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    self->_lf__set.physical_time_of_arrival = NEVER;
    #line 13 "/home/foobar/final/lingua_franca/src/lib/LED.lf"
    #endif // FEDERATED
    self->_lf__set.tmplt.type.element_size = sizeof(bool);
    return self;
}
