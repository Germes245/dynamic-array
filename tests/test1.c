#include <dyn_array.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
  
int main(){
    dyn_array array = dyn_array_init(0);
    assert(array.data == 0);

    dyn_array_append(&array, 5);
    uint8_t is_correct;
    size_t el = dyn_array_get_element(array, 0, &is_correct);
    assert(array.data[0] == 5 && el == 5 && is_correct == 1);

    dyn_array_append(&array, 10);
    el = dyn_array_get_element(array, 1, &is_correct);
    assert(array.data[1] == 10 && el == 10 && is_correct == 1);

    dyn_array_get_element(array, 10, &is_correct);
    assert(is_correct == 0);

    printf("проба на double-free\n");
    din_array_free(&array);
    din_array_free(&array);
    printf("прошло\n\n");
    assert(array.data == 0 && array.length == 0);

    printf("проба на use-after-free\n");
    dyn_array_append(&array, 10);
    dyn_array_append(&array, 10);
    printf("прошло\n\n");

    printf("проба на buffer overflow\n");

    dyn_array_get_element(array, 10, &is_correct);
    if(!is_correct) printf("понял что что-то нечисто: is_correct = %d\n", is_correct);
    printf("test passed!\n");
    return 0;
}