#include <assert.h>

#include "list.h"

int main() {
    list_t ls, copied;
    int result, *ptr;
    int **array;
    int sample[] = {1, 2, 3, 4};

    // List create test
    // List -> {1, 2, 3, 4}
    ls = list_create(sample, sample + 1, sample + 2, sample + 3);
    assert(ls);

    // List push pop tests
    // List {1, 2, 3, 4} -> {2, 3, 4}
    ptr = list_pop_front(ls);
    result = *ptr == 1;
    assert(result);

    // List {2, 3, 4} -> {2, 3}
    ptr = list_pop_back(ls);
    result = *ptr == 4;
    assert(result);

    // List {2, 3} -> {2, 3, 1}
    list_push_back(ls, sample);
    ptr = list_back(ls);
    result = *ptr == 1;
    assert(result);

    // List {2, 3, 1} -> {4, 2, 3, 1}
    list_push_front(ls, sample + 3);
    ptr = list_front(ls);
    result = *ptr == 4;
    assert(result);

    // List copy test
    // Copied {4, 2, 3, 1}
    copied = list_copy(ls);

    // List reverse test
    // List {4, 2, 3, 1} -> {1, 3, 2, 4}
    list_reverse(copied);
    ptr = list_pop_front(copied);
    result = *ptr == 1;
    assert(result);
    ptr = list_pop_front(copied);
    result = *ptr == 3;
    assert(result);
    ptr = list_pop_front(copied);
    result = *ptr == 2;
    assert(result);
    ptr = list_pop_front(copied);
    result = *ptr == 4;
    assert(result);

    // To array test
    array = (int**)list_to_array(ls);
    assert(*array[0] == 4);
    assert(*array[1] == 2);
    assert(*array[2] == 3);
    assert(*array[3] == 1);
       
    // List destroy test
    list_destroy(ls);
    list_destroy(copied);
    
    return 0;
}
