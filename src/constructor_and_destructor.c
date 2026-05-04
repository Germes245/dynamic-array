#include "dyn_array.h"
#include <stddef.h>

dyn_array dyn_array_init(size_t length){
    dyn_array array;
    if(length == 0){
        array.data = 0;
        array.length=0;
        return array;
    }
    array.length=length;
    array.data = malloc(length * sizeof(size_t));
    return array;
}

void din_array_free(dyn_array *array){
    free(array->data);
    array->length=0;
}