#include <stdio.h>
#include <assert.h>

#include "array.h"

int main(){
    array_t arr, copied;
    int result;
    int sample[] = {1, 2, 3, 4};

    // Array create test
    arr = array_create(int);
    assert(arr);

    // Array append and get test : array {1}
    array_append(arr, sample);
    int *ptr = array_get(arr, 0);
    result = sample[0] == *ptr;
    assert(result);

    // Array put test : array {3}
    array_put(arr, 0, sample + 2);
    ptr = array_get(arr, 0);
    result = sample[2] == *ptr;
    assert(result);
    
    // array {3, 2, 3}
    array_append(arr, sample + 1);
    array_append(arr, sample + 2);

    //Array remove test: array {3, 3}
    array_remove(arr, 1);
    ptr = array_get(arr, 0);
    result = *ptr == 3;
    assert(result);
    ptr = array_get(arr, 1);
    result = *ptr == 3;
    assert(result);
    assert(array_size(arr) == 2);

    // Array copied test
    copied = array_copy(arr);
    assert(copied);
    ptr = array_get(copied, 0);
    result = *ptr == 3;
    assert(result);
    ptr = array_get(copied, 1);
    result = *ptr == 3;
    assert(result);
    assert(array_size(copied) == 2);

    //Array destroy test
    array_destroy(arr);
    array_destroy(copied);
    
    return 0;
}