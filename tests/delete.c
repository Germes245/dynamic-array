#include <dyn_array.h>
#include <stdio.h>

int main(){
    dyn_array array = dyn_array_init(0);
    dyn_array_free(&array);
    dyn_array_free(&array);

    dyn_array_append(&array, 5);
    dyn_array_append(&array, 15);
    dyn_array_append(&array, 25);

    for(size_t i = 0; i < array.length; i++){
        printf("%d ", array.data[i]);
    }
    putchar('\n');

    uint8_t is_correct;
    dyn_array_delete(&array, 1, &is_correct);

    for(size_t i = 0; i < array.length; i++){
        printf("%d ", array.data[i]);
    }
    putchar('\n');
    return 0;
}