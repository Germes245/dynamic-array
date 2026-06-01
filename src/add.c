#include "dyn_array_{{prefix}}.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void dyn_array_{{prefix}}_unsafe_fast_append(dyn_array_{{prefix}} *array, {{type}} element){
    array->length++;
    array->data = realloc(array->data, array->length*sizeof({{type}}));
    array->data[array->length-1] = element;
}

void dyn_array_{{prefix}}_append(dyn_array_{{prefix}} *array, {{type}} element){
    if (array->length) dyn_array_{{prefix}}_unsafe_fast_append(array, element);
    else{
        array->length++;
        array->data = malloc(sizeof({{type}}));
        *array->data = element;
    }
}

void dyn_array_{{prefix}}_insert(dyn_array_{{prefix}} *array, size_t index, {{type}} element){
    if(index < array->length){
        if (index + 1 == array->length){
            dyn_array_{{prefix}}_unsafe_fast_append(array, element);
            return;
        }
        array->length++;
        array->data = realloc(array->data, array->length * sizeof({{type}}));
        size_t pointer_for_source = array->data + index;
        memmove(array->data + index + 1, array->data + index, (array->length - index) * sizeof({{type}}));
        array->data[index] = element;
    }
}