#include "dyn_array_{{type}}.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

dyn_array_{{type}} dyn_array_{{type}}_init(size_t length){
    dyn_array_{{type}} array;
    if(length == 0){
        array.data = 0;
        array.length=0;
        return array;
    }
    array.length=length;
    array.data = malloc(length * sizeof({{type}}));
    return array;
}

void dyn_array_{{type}}_unsafe_free(dyn_array_{{type}} *array){
    free(array->data);
    array->data = 0;
    array->length = 0;
}

void dyn_array_{{type}}_free(dyn_array_{{type}} *array){
    if(array->length) free(array->data);
    array->data = 0;
    array->length = 0;
}