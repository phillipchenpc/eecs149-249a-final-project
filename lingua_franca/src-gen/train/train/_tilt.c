#include "include/api/api.h"
#include "include/Tilt/Tilt.h"
#include "_tilt.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _tiltreaction_function_0(void* instance_args) {
    _tilt_self_t* self = (_tilt_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _tilt_x_t* x = self->_lf_x;
    int x_width = self->_lf_x_width; SUPPRESS_UNUSED_WARNING(x_width);
    _tilt_y_t* y = self->_lf_y;
    int y_width = self->_lf_y_width; SUPPRESS_UNUSED_WARNING(y_width);
    _tilt_z_t* z = self->_lf_z;
    int z_width = self->_lf_z_width; SUPPRESS_UNUSED_WARNING(z_width);
    _tilt_pitch_t* pitch = &self->_lf_pitch;
    #line 36 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    lf_set(pitch, atan2f(x->value, sqrtf(powf(y->value, 2) + powf(z->value, 2))) * 180 / M_PI);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _tiltreaction_function_1(void* instance_args) {
    _tilt_self_t* self = (_tilt_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _tilt_x_t* x = self->_lf_x;
    int x_width = self->_lf_x_width; SUPPRESS_UNUSED_WARNING(x_width);
    _tilt_y_t* y = self->_lf_y;
    int y_width = self->_lf_y_width; SUPPRESS_UNUSED_WARNING(y_width);
    _tilt_z_t* z = self->_lf_z;
    int z_width = self->_lf_z_width; SUPPRESS_UNUSED_WARNING(z_width);
    _tilt_roll_t* roll = &self->_lf_roll;
    #line 40 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    lf_set(roll, atan2f(y->value, sqrtf(powf(x->value, 2) + powf(z->value, 2))) * 180 / M_PI);
}
#include "include/api/set_undef.h"
_tilt_self_t* new__tilt() {
    _tilt_self_t* self = (_tilt_self_t*)_lf_new_reactor(sizeof(_tilt_self_t));
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Set input by default to an always absent default input.
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_x = &self->_lf_default__x;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Set the default source reactor pointer
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_default__x._base.source_reactor = (self_base_t*)self;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Set input by default to an always absent default input.
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_y = &self->_lf_default__y;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Set the default source reactor pointer
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_default__y._base.source_reactor = (self_base_t*)self;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Set input by default to an always absent default input.
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_z = &self->_lf_default__z;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    // Set the default source reactor pointer
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf_default__z._base.source_reactor = (self_base_t*)self;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_0.number = 0;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_0.function = _tiltreaction_function_0;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_0.self = self;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_0.name = "?";
    #line 35 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_1.number = 1;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_1.function = _tiltreaction_function_1;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_1.self = self;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_1.name = "?";
    #line 39 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__x.last = NULL;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__x.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__x_reactions[0] = &self->_lf__reaction_0;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__x_reactions[1] = &self->_lf__reaction_1;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__x.reactions = &self->_lf__x_reactions[0];
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__x.number_of_reactions = 2;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__x.physical_time_of_arrival = NEVER;
    #line 28 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED
    self->_lf__x.tmplt.type.element_size = sizeof(float);
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__y.last = NULL;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__y.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__y_reactions[0] = &self->_lf__reaction_0;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__y_reactions[1] = &self->_lf__reaction_1;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__y.reactions = &self->_lf__y_reactions[0];
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__y.number_of_reactions = 2;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__y.physical_time_of_arrival = NEVER;
    #line 29 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED
    self->_lf__y.tmplt.type.element_size = sizeof(float);
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__z.last = NULL;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__z.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__z_reactions[0] = &self->_lf__reaction_0;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__z_reactions[1] = &self->_lf__reaction_1;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__z.reactions = &self->_lf__z_reactions[0];
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__z.number_of_reactions = 2;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #ifdef FEDERATED
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    self->_lf__z.physical_time_of_arrival = NEVER;
    #line 30 "/home/foobar/final/lingua_franca/src/lib/Tilt.lf"
    #endif // FEDERATED
    self->_lf__z.tmplt.type.element_size = sizeof(float);
    return self;
}
