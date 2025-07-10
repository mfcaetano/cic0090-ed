//
// Created by mfcaetano on 2/14/25.
//

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void dfs_visit(Graph* graph, Vertex* vertex);


//-------------------------------------------------------------------
void breadth_first_search(struct vertex* start) {
    start->distance = 0;
    start->previus_vertex = NULL;

    Queue* queue = create_queue();
    Vertex* current = NULL;
    Node* nbr = NULL;

    enqueue(queue, start);

    while (!is_empty(queue)) {
        current = dequeue(queue);
        nbr = current->connect_to;

        while(nbr) {
            if (nbr->vertex->color == WHITE) {
                nbr->vertex->color = GRAY;
                nbr->vertex->distance = current->distance + 1;
                nbr->vertex->previus_vertex = current;
                enqueue(queue, nbr->vertex);
            }//end if color

            //next link list node
            nbr = nbr->next;
        }//end while

        current->color = BLACK;
    }//end while
}//end breadth_first_search()


//-------------------------------------------------------------------
void depth_first_search(Graph* graph) {
    Vertex* vertex = NULL;

    for(int i = 0; i < graph->size; i++) {
         vertex = graph->vertex_list[i];

        if(vertex) {
            vertex->color = WHITE;
            vertex->previus_vertex = NULL;
            vertex->distance = 0;
            vertex->time_discovered = 0;
            vertex->time_finished = 0;
        }//end if vertex
    }//end for i

    for(int i = 0; i < graph->size; i++) {
        vertex = graph->vertex_list[i];

        if(vertex) {
            if(vertex->color == WHITE)
                dfs_visit(graph, vertex);
        }//end if vertex
    }//end for i

}//end depth_first_search()


//-------------------------------------------------------------------
void dfs_visit(Graph* graph, Vertex* vertex) {
    vertex->color = GRAY;
    graph->time++;
    vertex->time_discovered = graph->time;
    Node* nbr = vertex->connect_to;

    while(nbr) {

        if(nbr->vertex->color == WHITE) {
            nbr->vertex->previus_vertex = vertex;
            dfs_visit(graph, nbr->vertex);
        }

        nbr = nbr->next;
    }//end nbr

    vertex->color = BLACK;
    graph->time++;
    vertex->time_finished = graph->time;
}//end dfs_visit()


//-------------------------------------------------------------------
void print_graph(Graph* graph) {
    Node* node = NULL;
    Vertex* prev = NULL;
    for(int i = 0; i < graph->size; i++) {
        Vertex* vertex = graph->vertex_list[i];

        if(vertex) {
            node = vertex->connect_to;

            printf("Vertex id: %d - connect_to [", vertex->id);

            if(!vertex->connect_to)
                printf("]");

            while(node) {
                if(node->next == NULL)
                    printf("%d (w:%d)]", node->vertex->id, node->weight);
                else
                    printf("%d (w:%d), ", node->vertex->id, node->weight);
                node = node->next;
            }//end while

            printf(" - color: %d - distance: %d  - disc: %d fin: %d\n", vertex->color, vertex->distance, vertex->time_discovered, vertex->time_finished);
            prev = vertex->previus_vertex;
            while(prev) {
                printf("        > Vertex id: %d - distance: %d - disc: %d fin: %d\n", prev->id, prev->distance, prev->time_discovered, prev->time_finished);
                prev = prev->previus_vertex;
            }//end while


        }//end if vertex
    }//end for i
}//end print_graph()


//-------------------------------------------------------------------
Vertex* create_vertex(int id) {
    Vertex* vertex = (Vertex *) malloc(sizeof(Vertex));

    if(vertex) {
        vertex->id = id;
        vertex->connect_to = NULL;
        vertex->distance = 0;
        vertex->time_discovered = 0;
        vertex->time_finished = 0;
        vertex->previus_vertex = NULL;
        vertex->color = WHITE;
    }

    return vertex;
}//end create_vertex()


//-------------------------------------------------------------------
Node* create_node(Vertex* vertex, int weight) {
    Node* node = (Node *) malloc(sizeof(Node));

    if(node) {
        node->vertex = vertex;
        node->next = NULL;
        node->weight = weight;
    }

    return node;
}//end create_node()


//-------------------------------------------------------------------
Graph* create_graph(int number_of_vertex) {
    Graph* graph = (Graph *) malloc(sizeof(Graph));

    if(graph) {
        graph->size = number_of_vertex;
        graph->time = 0;
        graph->vertex_list = (Vertex **) malloc(sizeof(Vertex *) * number_of_vertex);

        if(!graph->vertex_list) {
            printf("Error in creating graph\n");
            exit(1);
        }//end if vertex_list

        for(int i = 0; i < number_of_vertex; i++)
            graph->vertex_list[i] = NULL;
    }//end if graph

    return graph;
}//end create_graph()


//-------------------------------------------------------------------
void free_graph(Graph* graph) {
    if(graph) {
        Vertex* vertex = NULL;
        Node* node, *aux = NULL;

        for(int i = 0; i < graph->size; i++) {
            vertex = graph->vertex_list[i];

            if(vertex) {
                node = vertex->connect_to;

                while(node) {
                    aux = node;
                    node = node->next;
                    free(aux);
                }//end while

                free(vertex);
            }//end if vertex

        }//end for i

        free(graph->vertex_list);
        free(graph);
    }//end if graph

}//end free_graph()


//-------------------------------------------------------------------
int add_vertex(Graph* graph, Vertex* vertex) {
    for(int i = 0; i < graph->size; i++) {
        if(graph->vertex_list[i] == NULL) {
            graph->vertex_list[i] = vertex;
            return TRUE; //successful add operation
        }
    }

    return FALSE; //error to add
}//end add_vertex()


//-------------------------------------------------------------------
Vertex* get_vertex(Graph* graph, int id) {
    for(int i = 0; i < graph->size; i++) {
        if(graph->vertex_list[i]) {
            if(graph->vertex_list[i]->id == id)
                return graph->vertex_list[i];
        }//end if vertex_list
    }//end for i

    return NULL;
}//end get_vertex()


//-------------------------------------------------------------------
int add_neighbor(Vertex* vertex_src, Vertex* vertex_dst, int weight) {
    Node* new_node = create_node(vertex_dst, weight);

    if(!new_node) {
        printf("Error to allocate node structure\n");
        exit(1);
    }

    new_node->next = vertex_src->connect_to;
    vertex_src->connect_to = new_node;

    return TRUE;
}//end add_neighbor


//-------------------------------------------------------------------
int add_edge(Graph* graph, int id_vertex_src, int id_vertex_dst, int weight){
    Vertex* vertex_src = get_vertex(graph, id_vertex_src);
    Vertex* vertex_dst = get_vertex(graph, id_vertex_dst);

    // vertexs src or dst are not part of graph
    if(!vertex_src || !vertex_dst)
        return FALSE;

    add_neighbor(vertex_src, vertex_dst, weight);

    return TRUE;
}//end add_edge()
