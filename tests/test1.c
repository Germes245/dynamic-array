#include <dyn_array.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    dyn_array array = dyn_array_init(0);
    assert(array.data == 0);
    dyn_array_append(&array, 5);
    assert(array.data[0] == 5);
    dyn_array_append(&array, 10);
    assert(array.data[1] == 10);
    din_array_free(&array);
    assert(array.data == 0 && array.length == 0);
    printf("test passed!\n");
    return 0;
}