#include "dyn_array_{{prefix}}.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void dyn_array_{{prefix}}_unsafe_fast_append(dyn_array_{{prefix}} *array, {{type}} element){
    array->length++;
    array->data = realloc(array->data, array->length*sizeof({{type}}));
    array->data[array->length-1] = element;
}

void dyn_array_{{prefix}}_append(dyn_array_{{prefix}} *array, {{type}} element){
    if (array->length) dyn_array_{{prefix}}_unsafe_fast_append(array, element);
    else{
        array->length++;
        array->data = malloc(sizeof({{type}}));
        *array->data = element;
    }
}

void dyn_array_{{prefix}}_insert(dyn_array_{{prefix}} *array, size_t index, {{type}} element){
    if(index < array->length){
        if (index + 1 == array->length){
            dyn_array_{{prefix}}_unsafe_fast_append(array, element);
            return;
        }
        array->length++;
        array->data = realloc(array->data, array->length * sizeof({{type}}));
        memmove(array->data + index + 1, array->data + index, (array->length - index) * sizeof({{type}}));
        array->data[index] = element;
    }
}

void dyn_array_{{prefix}}_memory_append(dyn_array_{{prefix}} *array, {{type}} *src, size_t length) {
    if (array == NULL || length == 0 || src == NULL) {
        return; // некорректные аргументы – ничего не делаем
    }

    size_t new_length = array->length + length;
    {{type}} *new_data = realloc(array->data, new_length * sizeof({{type}}));
    if (new_data == NULL) {
        // Ошибка выделения памяти – массив остаётся прежним
        return;
    }

    // Копируем новые элементы в конец
    memcpy(new_data + array->length, src, length * sizeof({{type}}));

    // Обновляем структуру
    array->data = new_data;
    array->length = new_length;
}