#define dyn_array_init(array, length){\
    if(length == 0){\
        array.data = 0;\
        array.length=0;\
        return array;\
    }\
    array.length=length;\
    array.data = malloc(length * sizeof(size_t));\
}