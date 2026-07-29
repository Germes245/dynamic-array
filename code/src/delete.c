#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio.h>
#include "dyn_array_{{prefix}}.h"

type dyn_array_{{prefix}}_unsave_fast_pop(dyn_array_{{prefix}} *array){ // если уверены что массив имеет больше 1 элемента, то используете это для оптимизации
    type return_value = array->data[--array->length];
    array->data = realloc(array->data, array->length);
    return return_value;
}

type dyn_array_{{prefix}}_safety_pop(dyn_array_{{prefix}} *array, uint8_t *array_has_element){
    if (array->length > 1) {
        *array_has_element = 1;
        return dyn_array_{{prefix}}_unsave_fast_pop(array);
    }
    else if (array->length == 1){
        type return_value = *array->data;
        free(array->data);
        array->data = 0;
        array->length = 0;
        *array_has_element = 1;
        return return_value;
    }
    else {
        *array_has_element = 0;
    }
}

type dyn_array_{{prefix}}_delete(dyn_array_{{prefix}}* array, size_t index, uint8_t *array_has_element){
    //printf("\n%d\n", array->data[0]);
    if (index < array->length){
        if (array->length == 1){
            *array_has_element = 1;
            type return_value = *array->data;
            free(array->data);
            array->data = 0;
            array->length = 0;
            return return_value;
        }
        if (index + 1 == array->length) return dyn_array_{{prefix}}_safety_pop(array, array_has_element);

        *array_has_element = 1;
        type return_value = array->data[index];
        memmove(array->data + index, array->data + index + 1, (array->length - index - 1) * sizeof(type));
        array->data = realloc(array->data, (--array->length)*sizeof(type));
        return return_value;
    }
    *array_has_element = 0;
}
