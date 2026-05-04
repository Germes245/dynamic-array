#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t *data;
    size_t length;
} dyn_array; // (dynamic array)

// constructor and destructor

dyn_array dyn_array_init(size_t length);
void din_array_free(dyn_array *array);

// add element

void dyn_array_append(dyn_array *array, size_t element);
void dyn_array_safe_insert(dyn_array *array, size_t index, size_t element);

// delete element

size_t dyn_array_safety_pop(dyn_array *array, uint8_t *array_has_element);