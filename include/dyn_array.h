#include <stddef.h>
#include <stdint.h>

/** @mainpage Документация проекта "dynamic array"
 *
 * @section intro это библиотека для удобной работы с массивами указателей в языке програмирования C.
 * @section api API:
 * Основные функции описаны в файле @ref dyn_array.h.
 * @file dyn_array.h
 * @brief объявление главных методов динамического массива
*/

typedef struct {
    size_t *data;
    size_t length;
} dyn_array; // (dynamic array)

// constructor and destructor

/**
 * @brief инициализирует динамический массив
 * @param length -- первоначальная длина массива
 * @details если длина массива равна нулю, то указатель на динамический массив будет содержать цифру 0
*/
dyn_array dyn_array_init(size_t length);

/**
 * @brief освобождает память, которая использовалась для массива
 * @param array -- динамический массив
 *
*/
void dyn_array_free(dyn_array *array);

// add element

void dyn_array_append(dyn_array *array, size_t element);
void dyn_array_safe_insert(dyn_array *array, size_t index, size_t element);

// delete element

size_t dyn_array_safety_pop(dyn_array *array, uint8_t *array_has_element);

//get element
size_t dyn_array_get_element(dyn_array array, size_t index, uint8_t *is_correct_index);
uint8_t dyn_array_set_element(dyn_array* array, size_t index, size_t element);