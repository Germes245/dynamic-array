#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "dyn_array.h"

size_t dyn_array_unsave_fast_pop(dyn_array *array){ // если уверены что массив имеет больше 1 элемента, то используете это для оптимизации
    size_t return_value = array->data[--array->length];
    array->data = realloc(array->data, array->length);
    return return_value;
}

size_t dyn_array_safety_pop(dyn_array *array, uint8_t *array_has_element){
    if (array->length > 1) {
        *array_has_element = 1;
        return dyn_array_unsave_fast_pop(array);
    }
    else if (array->length == 1){
        size_t return_value = *array->data;
        free(array->data);
        array->length = 0;
    }
    else {
        *array_has_element = 0;
    }
}