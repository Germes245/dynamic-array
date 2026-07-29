#include "dyn_array_{{prefix}}.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

dyn_array_{{prefix}} dyn_array_{{prefix}}_init(size_t length){
    dyn_array_{{prefix}} array;
    if(length == 0){
        array.data = 0;
        array.length=0;
        return array;
    }
    array.length=length;
    array.data = malloc(length * sizeof(type));
    return array;
}

void dyn_array_{{prefix}}_unsafe_free(dyn_array_{{prefix}} *array){
    free(array->data);
    array->data = 0;
    array->length = 0;
}

void dyn_array_{{prefix}}_free(dyn_array_{{prefix}} *array){
    if(array->length) free(array->data);
    array->data = 0;
    array->length = 0;
}