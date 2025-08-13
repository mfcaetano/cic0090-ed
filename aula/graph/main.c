#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

  Graph* graph = create_graph(10);
  
  free_graph(graph);

  for (int i = 0; i < 7; i++) {
      if(!add_vertex(graph, create_vertex(i))) {
          printf("Failed to add vertex %d\n", i);
          exit(1);
      }
  }
/*
    add_edge(graph, 0, 1, 5);
    add_edge(graph, 0, 5, 2);
    add_edge(graph, 1, 2, 4);
    add_edge(graph, 2, 3, 9);
    add_edge(graph, 3, 4, 7);
    add_edge(graph, 3, 5, 3);
    add_edge(graph, 4, 0, 1);
    add_edge(graph, 5, 0, 2);
    add_edge(graph, 5, 2, 1);
    add_edge(graph, 5, 4, 8);

    Vertex* start = get_vertex(graph, 5);

    breadth_first_search(start);


    printf("BFS: \n");
    print_graph(graph);

    free_graph(graph);
*/
    /*graph = create_graph(7);

    for (int i = 0; i < 7; i++) {
        if(!add_vertex(graph, create_vertex(i))) {
            printf("Failed to add vertex %d\n", i);
            exit(1);
        }
    }

    add_edge(graph, 0, 1, 0);
    add_edge(graph, 0, 3, 0);
    add_edge(graph, 1, 2, 0);
    add_edge(graph, 1, 3, 0);
    add_edge(graph, 3, 4, 0);
    add_edge(graph, 4, 1, 0);
    add_edge(graph, 4, 5, 0);
    add_edge(graph, 5, 2, 0);


    depth_first_search(graph);

    printf("\n\nDFS: \n");
    print_graph(graph);

    free_graph(graph);*/
    
}
