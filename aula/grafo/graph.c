#include "graph.h"

#include <stdio.h>
#include <stdlib.h>


//-------------------------------------------------------------------
void print_graph(Graph* graph) {
    Node* node = NULL;
    for(int i = 0; i < graph->size; i++) {
        Vertex* vertex = graph->vertex_list[i];

        if(vertex) {
            node = vertex->connect_to;

            printf("Vertex id: %d - connect_to [", vertex->id);

            if(!vertex->connect_to)
                printf("]\n");

            while(node) {
                if(node->next == NULL)
                    printf("%d (w:%d)]\n", node->vertex->id, node->weight);
                else
                    printf("%d (w:%d), ", node->vertex->id, node->weight);
                node = node->next;
            }//end while
        }//end if vertex
    }//end for i
}//end print_graph()


Vertex* create_vertex(int id){
    Vertex* vertex = (Vertex *) malloc(sizeof(Vertex));

    if(vertex){
        vertex->id = id;

        vertex->connect_to = NULL;
    }//end if

    return vertex;
}//end create_vertex()


Node* create_node(Vertex* vertex, int weight){
    Node* node = (Node *) malloc(sizeof(Node));

    if(node){
        node->vertex = vertex;
        node->weight = weight;
        node->next = NULL;
    }

    return node;
}//end create_node()


Graph* create_graph(int number_of_vertex){
    Graph* graph = (Graph *) malloc(sizeof(Graph));

    if(graph){
        graph->size = number_of_vertex;

        graph->vertex_list = (Vertex **) malloc(number_of_vertex*sizeof(Vertex *));

        if(!graph->vertex_list){
            printf("Erro criando graph!");
            exit(1);
        }

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




int add_vertex(Graph* graph, Vertex* vertex){
        for(int i = 0; i < graph->size; i++){
            if(graph->vertex_list[i] == NULL){
                graph->vertex_list[i] = vertex;

                return TRUE;
            }
        }

    return FALSE;
}//end add_vertex()


Vertex* get_vertex(Graph* graph, int id){

    for(int i = 0; i < graph->size; i++){

        if(graph->vertex_list[i]){

            if (graph->vertex_list[i]->id == id){
                return graph->vertex_list[i];
            }
        }

    }//end for i

    return NULL;
}//end get_vertex()


int add_edge(Graph* graph, int id_vertex_src, int id_vertex_dst, int weight){
    Vertex* vertex_src = get_vertex(graph, id_vertex_src);
    Vertex* vertex_dst = get_vertex(graph, id_vertex_dst);

    if(!vertex_src || !vertex_dst)
        return FALSE;

    add_neighbor(vertex_src, vertex_dst, weight);

    return TRUE;
}//end add_edge()


int add_neighbor(Vertex* vertex_src, Vertex* vertex_dst, int weight){
    Node* new_node = create_node(vertex_dst, weight);

    if(!new_node){
        printf("Erro ao alocar da estrutura do tipo no \n");
        exit(1);
    }

    new_node->next = vertex_src->connect_to;
    vertex_src->connect_to = new_node;


    return TRUE;
}//end add neighbor
