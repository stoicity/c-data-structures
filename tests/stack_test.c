#include <assert.h>

#include "stack.h"

int main(){
    stack_t stk;
    int result, *ptr;
    int sample[] = {1, 2, 3, 4};

    // Stack create test
    stk = stack_create();
    assert(stk);

    // Stack push and top test: 
    // Stack {1}
    stack_push(stk, sample);
    ptr = stack_top(stk);
    result = *ptr == 1;
    assert(result);

    // Stack {3, 2, 1}
    stack_push(stk, sample + 1);
    stack_push(stk, sample + 2);

    //Stack {2, 1}
    ptr = stack_pop(stk);
    result = *ptr == 3;
    assert(result);

    // Stack {2, 1}
    ptr = stack_top(stk);
    result = *ptr == 2;
    assert(result);

    // Stack {2, 2, 1}
    stack_push(stk, sample + 1);
    assert(stack_size(stk) == 3);

    ptr = stack_pop(stk);
    result = *ptr == 2;
    assert(result);
    
    // Stack {2, 1}
    ptr = stack_pop(stk);
    result = *ptr == 2;
    assert(result);

    // Stack {1}
    ptr = stack_pop(stk);
    result = *ptr == 1;
    assert(result);

    // Stack destroy test
    stack_destroy(stk);

    return 0;
}
