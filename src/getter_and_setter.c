#include "dyn_array.h"
#include <stddef.h>
#include <stdint.h>

size_t dyn_array_get_element(dyn_array array, size_t index, uint8_t *is_correct_index){
    if(index < array.length){
        *is_correct_index = 1;
        return array.data[index];
    }
    *is_correct_index = 0;
    return;
}

uint8_t dyn_array_set_element(dyn_array* array, size_t index, size_t element){ // если проверка границ пройдена, то возвращает 0, иначе 1
    if(index < array->length){
        array->data[index] = element;
        return 0;
    }
    return 1;
}