#include "dyn_array.h"
#include <stddef.h>
#include <stdlib.h>

void dyn_array_append(dyn_array *array, size_t element){
    if (array->length) {
        array->length++;
        array->data = realloc(array->data, array->length);
        array->data[array->length-1] = element;
    }
    else{
        array->length++;
        array->data = malloc(sizeof(size_t));
        *array->data = element;
    }
}