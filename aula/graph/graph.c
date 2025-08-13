#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

Vertex* create_vertex(int id){
  Vertex* vertex = (Vertex *) malloc(sizeof(Vertex));

  if(vertex){
    vertex->id = id;
    vertex->connect_to = NULL;
  }
  
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
    
    graph->vertex_list = (Vertex **) malloc(sizeof(Vertex *)*number_of_vertex);
    
    if(graph->vertex_list){
      for(int i = 0; i < number_of_vertex; i++)
        graph->vertex_list[i] = NULL;
    }
  }//end if graph
  
  return graph;
}//end create_graph()


void free_graph(Graph* graph){
  if(graph){
    Vertex* vertex = NULL;
    Node* node, *aux = NULL;
    
    for(int i = 0; i < graph->size; i++){
      vertex = graph->vertex_list[i];
      
      if(vertex){
        node = vertex->connect_to;
        
        while(node){
          aux = node;
          node = node->next;
          free(aux);
        }//end while
        
        free(vertex);
      }
    }//end for i
    
    free(graph->vertex_list);
    free(graph);
    
  }//end if graph

}//end free_graph


int add_vertex(Graph* graph, Vertex* vertex){
  for(int i = 0; i < graph->size; i++){
    if(!graph->vertex_list[i]){
      graph->vertex_list[i] = vertex;
      return TRUE;
    }
  }//end for i
  
  return FALSE;
}//end add_vertex

Vertex* get_vertex(Graph* graph, int id){
}

int add_edge(Graph* graph, int id_vertex_src, int id_vertex_dst, int weight){
}

int add_neighbor(Vertex* vertex_src, Vertex* vertex_dst, int weight){
}

void print_graph(Graph* graph){
}
