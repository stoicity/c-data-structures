#include <assert.h>

#include "queue.h"

int main(){
    queue_t q;
    int result, *ptr;
    int sample[] = {1, 2, 3, 4};

    // Queue create test
    // Queue -> {}
    q = queue_create();
    assert(q);

    // Queue enqueue and dequeue tests
    // Queue {} -> {1, 2}
    queue_enqueue(q, sample);
    queue_enqueue(q, sample + 1);
    ptr = queue_head(q);
    result = *ptr == 1;
    assert(result);
    ptr = queue_tail(q);
    result = *ptr == 2;
    assert(result);


    // Queue {1, 2} -> {2}
    ptr = queue_dequeue(q);
    result = *ptr == 1;
    assert(result);

    // Queue {2} -> {2, 4}
    queue_enqueue(q, sample + 3);
    ptr = queue_tail(q);
    result = *ptr == 4;
    assert(result);
    assert(queue_size(q) == 2);

    // Queue destroy test
    queue_destroy(q);

    return 0;
}
