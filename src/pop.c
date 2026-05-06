#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "dyn_array.h"

size_t dyn_array_safety_pop(dyn_array *array, uint8_t *array_has_element){
    if (array->length) {
        *array_has_element = 1;
        size_t return_value = array->data[--array->length];
        array->data = realloc(array->data, array->length*sizeof(size_t));
        return return_value;
    }
    else {
        *array_has_element = 0;
    }
}

size_t dyn_array_unsave_fast_pop(dyn_array *array){
    size_t return_value = array->data[--array->length];
    array->data = realloc(array->data, array->length);
    return return_value;
}