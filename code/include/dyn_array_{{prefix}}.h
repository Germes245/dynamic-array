#include <stddef.h>
#include <stdint.h>
#include "type.h"

/** @mainpage Документация проекта "dynamic array"
 *
 * @section intro это библиотека для удобной работы с динамическими массивами в языке програмирования C.
 * @section api API:
 * Основные функции описаны в файле @ref dyn_array_{{prefix}}.h.
 * @file dyn_array_{{prefix}}.h
 * @brief объявление главных методов динамического массива
*/

typedef struct {
    type *data;
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
 * @param array -- структура динамического массива
 * @details если массив был освобождён или не имеет элементов, то не делает двойное освобождение
*/
void dyn_array_{{prefix}}_free(dyn_array_{{prefix}} *array);

// add element

/**
 * @brief добавляет элемент в конец массива
 * @param *array -- указатель на структуру динамического массива, element -- добавляемый элемент
 * @details если массив пустой или был когда-то освобождён, то аллоцирует новый
*/
void dyn_array_{{prefix}}_append(dyn_array_{{prefix}} *array, type element);

/**
 * @brief быстро, без проверки на существование массива добавляет элемент в конец массива.
 * @param *array -- указатель на структуру динамического массива, element -- добавляемый элемент
 * @details если массив пустой или был когда-то освобождён, то может произойти segfault
*/
void dyn_array_{{prefix}}_unsafe_fast_append(dyn_array_{{prefix}} *array, type element);

/**
 * @brief вставляет элемент в заданную позицию в массиве
 * @param *array -- указатель на структуру динамического массива, index -- заданая позиция вставки, element -- добавляемый элемент
*/
void dyn_array_{{prefix}}_insert(dyn_array_{{prefix}} *array, size_t index, type element);

// delete element

/**
 * @brief удаляет элемент в конце массива и возвращает его
 * @param *array -- указатель на структуру динамического массива, *array_has_element -- проверка на границы массива, если границы соблюдены, то 1, иначе 0
 * @details делает проверку на размер массива, так как реализации удаления в зависимости от длины разные
*/
type dyn_array_{{prefix}}_safety_pop(dyn_array_{{prefix}} *array, uint8_t *array_has_element);

/**
 * @brief удаляет элемент в конце массива без проверки длины и возвращает его
 * @param *array -- указатель на структуру динамического массива
 * @details стоит использовать, если длина массива будет больше 1. если точно не известно, то стоит использовать dyn_array_{{prefix}}_safety_pop
*/
type dyn_array_{{prefix}}_unsave_fast_pop(dyn_array_{{prefix}} *array);

/**
 * @brief удаляет элемент в заданой позиции
 * @param *array -- указатель на структуру динамического массива, index -- задаваемая позиция, *array_has_element -- проверка на границы массива, если границы соблюдены, то 1, иначе 0
*/
type dyn_array_{{prefix}}_delete(dyn_array_{{prefix}}* array, size_t index, uint8_t *array_has_element);

//get element

/**
 * @brief получение элемента с проверкой на границы массива
 * @param *array -- указатель на структуру динамического массива, index -- задаваемая позиция, *array_has_element -- проверка на границы массива, если границы соблюдены, то 1, иначе 0
*/
type dyn_array_{{prefix}}_get_element(dyn_array_{{prefix}} array, size_t index, uint8_t *is_correct_index);

/**
 * @brief изменение элемента с проверкой на границы массива
 * @param *array -- указатель на структуру динамического массива
 * @param index -- задаваемая позиция
 * @param element -- элемент
*/
uint8_t dyn_array_{{prefix}}_set_element(dyn_array_{{prefix}}* array, size_t index, type element);

// конкатенация массивов

/**
 * @brief Конкатенация первого динамического массива c другим вторым массивом.
 * @param *array -- указатель на структуру динамического массива.
 * @param *src   -- указатель на добавляемый массив (обычный C-массив).
 * @param length -- длина добавляемого массива.
 * @details Если length == 0, функция ничего не делает.
 *          Если выделение памяти не удалось, массив остаётся неизменным.
 * пример:
 * динамический массив содержит числа 13, 35, 88, а второй массив 12, 24.
 * динамический массив после конкатенации имеет числа 13, 35, 88, 12, 24.
 * ``` c
 * type array2[] = {12,24};
 * dyn_array_{{prefix}}_memory_append(&array1, array2, sizeof(array2)/sizeof(array2[0])); 
 * ```
*/
void dyn_array_{{prefix}}_memory_append(dyn_array_{{prefix}} *array, type *src, size_t length);