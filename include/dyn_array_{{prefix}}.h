#include <stddef.h>
#include <stdint.h>

/** @mainpage Документация проекта "dynamic array"
 *
 * @section intro это библиотека для удобной работы с массивами указателей в языке програмирования C.
 * @section api API:
 * Основные функции описаны в файле @ref dyn_array_{{prefix}}.h.
 * @file dyn_array_{{prefix}}.h
 * @brief объявление главных методов динамического массива
*/

typedef struct {
    {{type}} *data;
    size_t length;
} dyn_array_{{prefix}}; // (dynamic array)

// constructor and destructor

/**
 * @brief инициализирует динамический массив
 * @param length -- первоначальная длина массива
 * @details если длина массива равна нулю, то указатель на динамический массив будет содержать цифру 0
*/
dyn_array_{{prefix}} dyn_array_{{prefix}}_init(size_t length);

/**
 * @brief освобождает память, которая использовалась для массива
 * @param array -- динамический массив
 *
*/
void dyn_array_{{prefix}}_free(dyn_array_{{prefix}} *array);

// add element

void dyn_array_{{prefix}}_append(dyn_array_{{prefix}} *array, {{type}} element);
void dyn_array_{{prefix}}_unsafe_fast_append(dyn_array_{{prefix}} *array, {{type}} element);
void dyn_array_{{prefix}}_insert(dyn_array_{{prefix}} *array, size_t index, {{type}} element);

// delete element

{{type}} dyn_array_{{prefix}}_safety_pop(dyn_array_{{prefix}} *array, uint8_t *array_has_element);
{{type}} dyn_array_{{prefix}}_delete(dyn_array_{{prefix}}* array, size_t index, uint8_t *array_has_element);

//get element
{{type}} dyn_array_{{prefix}}_get_element(dyn_array_{{prefix}} array, size_t index, uint8_t *is_correct_index);
uint8_t dyn_array_{{prefix}}_set_element(dyn_array_{{prefix}}* array, size_t index, {{type}} element);