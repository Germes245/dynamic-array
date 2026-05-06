#include "dyn_array.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void dyn_array_unsafe_fast_append(dyn_array *array, size_t element){
    array->length++;
    array->data = realloc(array->data, array->length*sizeof(size_t));
    array->data[array->length-1] = element;
}

void dyn_array_append(dyn_array *array, size_t element){
    if (array->length) dyn_array_unsafe_fast_append(array);
    else{
        array->length++;
        array->data = malloc(sizeof(size_t));
        *array->data = element;
    }
}

void dyn_array_insert(dyn_array *array, size_t index, size_t element){
    if(index < array->length){
        if (index + 1 == array->length){
            dyn_array_unsafe_fast_append(array, element);
            return;
        }
        array->length++;
        array->data == realloc(array->data, array->length);
        //memmove(void *, const void *, __size_t)
    }
}