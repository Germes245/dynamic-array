#include "dyn_array_{{prefix}}.h"
#include <stddef.h>
#include <stdint.h>

{{type}} dyn_array_{{prefix}}_get_element(dyn_array_{{prefix}} array, size_t index, uint8_t *is_correct_index){
    if(index < array.length){
        *is_correct_index = 1;
        return array.data[index];
    }
    *is_correct_index = 0;
    return;
}

uint8_t dyn_array_{{prefix}}_set_element(dyn_array_{{prefix}}* array, size_t index, {{type}} element){ // если проверка границ пройдена, то возвращает 0, иначе 1
    if(index < array->length){
        array->data[index] = element;
        return 0;
    }
    return 1;
}