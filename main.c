#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t *data;
    size_t length;
} dyn_array; // (dynamic array)

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

int main(){
    dyn_array array = dyn_array_init(0);
    dyn_array_append(&array, 5);
    dyn_array_append(&array, 10);
    printf("%d %d\n", array.data[0], array.data[1]);
    din_array_free(&array);
    return 0;
}