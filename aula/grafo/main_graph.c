#include <stdio.h>
#include <stdlib.h>

#include "graph.h"


int main(void) {
    Graph* graph = create_graph(6);


    for(int i = 0; i < 6; i++)
        if( !add_vertex(graph, create_vertex(i)) ){
            printf("Falha em criar o vertice %d \n", i);
            exit(1);
        }


    add_edge(graph, 0, 1, 5);
    add_edge(graph, 0, 5, 2);
    add_edge(graph, 1, 2, 4);
    add_edge(graph, 2, 3, 9);
    add_edge(graph, 3, 4, 7);
    add_edge(graph, 3, 5, 3);
    add_edge(graph, 4, 0, 1);
    add_edge(graph, 5, 2, 1);
    add_edge(graph, 5, 4, 8);


    print_graph(graph);

    free_graph(graph);


    return 0;
}