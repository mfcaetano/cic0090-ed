//
// Created by Marcos F. Caetano on 23/10/19.
//

#ifndef ARVORE_QUEUE_H
#define ARVORE_QUEUE_H

#include <stdbool.h>
#include "binary_tree.h"

typedef struct element_t{
    node_t* data;
    struct element_t* next;
} element_t;

typedef struct{
    element_t* first;
    element_t* last;
} queue_t;

element_t* get_element(node_t* data);
queue_t*   get_queue();
void       free_queue(queue_t* queue);

_Bool      isEmpty(queue_t* queue);
_Bool      enqueue(queue_t* queue, node_t* data);
_Bool      dequeue(queue_t* queue, node_t** data);
_Bool      get_head(queue_t* queue, node_t** data);
void       print(queue_t* queue);


#endif //ARVORE_QUEUE_H
