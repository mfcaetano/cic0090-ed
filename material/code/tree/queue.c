//
// Created by Marcos F. Caetano on 23/10/19.
//

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


//----------------------------------------------
element_t* get_element(node_t* data){
    element_t* e = (element_t *) malloc(sizeof(element_t));

    if(!e)
        return NULL;

    e->data = data;
    e->next = NULL;

    return e;
}//end get_element()

//----------------------------------------------
queue_t* get_queue(){
    queue_t* queue = (queue_t *) malloc(sizeof(queue_t));

    if(!queue)
        return NULL;

    queue->first = NULL;
    queue->last  = NULL;

    return queue;
}//end get_queue()


//----------------------------------------------
_Bool isEmpty(queue_t* queue){
    return (!queue || (!queue->first && !queue->last));
}//end isEmpty()

//----------------------------------------------
void free_queue(queue_t* queue){
    element_t* aux = NULL;

    if(!queue)
        return;

    aux = queue->first;

    while(queue->first){
        queue->first = queue->first->next;
        free(aux);
        aux = queue->first;
    }

    free(queue);
}//end free_queue()

//----------------------------------------------
_Bool enqueue(queue_t* queue, node_t* data){
    element_t* e = get_element(data);

    if(!e)
        return false;

    if(isEmpty(queue)){
        queue->first = e;
        queue->last  = e;
    }else{
        queue->last->next = e;
        queue->last       = e;
    }

    return true;
}//end enqueue()


//----------------------------------------------
_Bool dequeue(queue_t* queue, node_t** data){
    element_t* e = NULL;

    if(isEmpty(queue))
        return false;

    e = queue->first;

    if(queue->first == queue->last){
        queue->first = NULL;
        queue->last  = NULL;
    }else{
        queue->first = queue->first->next;
    }

    *data = e->data;

    free(e);
    return true;
}//end dequeue()

//----------------------------------------------
_Bool get_head(queue_t* queue, node_t** data){

    if(isEmpty(queue))
        return false;

    *data = queue->first->data;
    return true;
}//end get_head()


//----------------------------------------------
void print(queue_t* queue){
    element_t* e = NULL;

    if(isEmpty(queue))
        return;

    e = queue->first;

    while(e){
        printf("%d, ", e->data->data);

        e = e->next;
    }

    printf("\n");
}//end print()
