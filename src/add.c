#include "dyn_array.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void dyn_array_unsafe_fast_append(dyn_array *array, size_t element){
    array->length++;
    array->data = realloc(array->data, array->length*sizeof(size_t));
    array->data[array->length-1] = element;
}

void dyn_array_append(dyn_array *array, size_t element){
    if (array->length) dyn_array_unsafe_fast_append(array, element);
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
        for(size_t i = 0; i < array->length; i++){
            printf("%d ", array->data[i]);
        }
        putchar('\n');
        size_t pointer_for_source = array->data + index*sizeof(size_t);
        memmove(pointer_for_source + sizeof(size_t), pointer_for_source, array->length - index - sizeof(size_t));
        array->data[index] = element;
    }
}