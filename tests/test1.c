#include <dyn_array_{{prefix}}.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
  
int main(){
    dyn_array_{{prefix}} array = dyn_array_{{prefix}}_init(0);
    assert(array.data == 0);

    dyn_array_{{prefix}}_append(&array, 5);
    uint8_t is_correct;
    {{type}} el = dyn_array_{{prefix}}_get_element(array, 0, &is_correct);
    assert(array.data[0] == 5 && el == 5 && is_correct == 1);

    dyn_array_{{prefix}}_append(&array, 10);
    //dyn_array_{{prefix}}_get_element(array, 10);
    el = dyn_array_{{prefix}}_get_element(array, 1, &is_correct);
    assert(array.data[1] == 10 && el == 10 && is_correct == 1);

    dyn_array_{{prefix}}_get_element(array, 10, &is_correct);
    assert(is_correct == 0);

    printf("проба на double-free\n");
    dyn_array_{{prefix}}_free(&array);
    dyn_array_{{prefix}}_free(&array);
    printf("прошло\n\n");
    assert(array.data == 0 && array.length == 0);

    printf("проба на use-after-free\n");
    dyn_array_{{prefix}}_append(&array, 1);
    dyn_array_{{prefix}}_append(&array, 25);
    dyn_array_{{prefix}}_append(&array, 50);
    printf("прошло\n\n");

    printf("проба на buffer overflow\n");

    dyn_array_{{prefix}}_get_element(array, 10, &is_correct);
    if(!is_correct) printf("понял что что-то нечисто: is_correct = %d\n", is_correct);
    printf("прошло\n\n");
    printf("insert\nбыло: ");
    for(size_t i = 0; i < array.length; i++){
        printf("%d ", array.data[i]);
    }
    putchar('\n');
    dyn_array_{{prefix}}_insert(&array, 0, 1);
    printf("стало: ");
    for(size_t i = 0; i < array.length; i++){
        printf("%d ", array.data[i]);
    }
    putchar('\n');

    printf("delete\nбыло: ");
    for(size_t i = 0; i < array.length; i++){
        printf("%d ", array.data[i]);
    }
    putchar('\n');
    dyn_array_{{prefix}}_delete(&array, 1, &is_correct);
    printf("стало: ");
    for(size_t i = 0; i < array.length; i++){
        printf("%d ", array.data[i]);
    }
    putchar('\n');
    printf("test passed!\n");
    return 0;
}