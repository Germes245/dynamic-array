#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio.h>
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
        array->data = 0;
        array->length = 0;
        *array_has_element = 1;
        return return_value;
    }
    else {
        *array_has_element = 0;
    }
}

size_t dyn_array_delete(dyn_array* array, size_t index, uint8_t *array_has_element){
    //printf("\n%d\n", array->data[0]);
    if (index < array->length){
        if (array->length == 1){
            *array_has_element = 1;
            size_t return_value = *array->data;
            free(array->data);
            array->data = 0;
            array->length = 0;
            return return_value;
        }
        if (index + 1 == array->length) return dyn_array_safety_pop(array, array_has_element);

        *array_has_element = 1;
        size_t return_value = array->data[index];
        memmove(array->data + index, array->data + index + 1, array->length - index - 1);
        array->data = realloc(array->data, --array->length);
        return return_value;
    }
    *array_has_element = 0;
}
