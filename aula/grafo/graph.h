//
// Created by mfcaetano on 2/14/25.
//

#ifndef GRAPH_H
#define GRAPH_H

#define TRUE 1
#define FALSE 0


typedef struct vertex{
	int id;
	struct node* connect_to;
} Vertex;

typedef struct node{
	struct vertex* vertex;
	struct node* next;
	int weight;
} Node;


typedef struct graph{
	struct vertex** vertex_list;
	int size;
} Graph;



Vertex* create_vertex(int id);
Node* create_node(Vertex* vertex, int weight);
Graph* create_graph(int number_of_vertex);
void free_graph(Graph* graph);

int add_vertex(Graph* graph, Vertex* vertex);
Vertex* get_vertex(Graph* graph, int id);

int add_edge(Graph* graph, int id_vertex_src, int id_vertex_dst, int weight);

int add_neighbor(Vertex* vertex_src, Vertex* vertex_dst, int weight);








void print_graph(Graph* graph);



#endif //GRAPH_H