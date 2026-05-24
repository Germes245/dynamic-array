#include "dyn_array_{{type}}.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void dyn_array_{{type}}_unsafe_fast_append(dyn_array_{{type}} *array, {{type}} element){
    array->length++;
    array->data = realloc(array->data, array->length*sizeof({{type}}));
    array->data[array->length-1] = element;
}

void dyn_array_{{type}}_append(dyn_array_{{type}} *array, {{type}} element){
    if (array->length) dyn_array_{{type}}_unsafe_fast_append(array, element);
    else{
        array->length++;
        array->data = malloc(sizeof({{type}}));
        *array->data = element;
    }
}

void dyn_array_{{type}}_insert(dyn_array_{{type}} *array, size_t index, {{type}} element){
    if(index < array->length){
        if (index + 1 == array->length){
            dyn_array_{{type}}_unsafe_fast_append(array, element);
            return;
        }
        array->length++;
        array->data == realloc(array->data, array->length);
        size_t pointer_for_source = array->data + index*sizeof({{type}});
        memmove(pointer_for_source + sizeof({{type}}), pointer_for_source, array->length - index - sizeof({{type}}));
        array->data[index] = element;
    }
}