#include <stddef.h>

typedef struct {
    size_t *data;
    size_t length;
} dyn_array; // (dynamic array)

// constructor and destructor

dyn_array dyn_array_init(size_t length);
void din_array_free(dyn_array *array);

