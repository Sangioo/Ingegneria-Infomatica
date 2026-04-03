#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "graph_services.h"

	
int main(int argc, char **argv) {
	graph *gra = graph_new();
	
	graph_node *a = graph_add_node(gra, "a");
	graph_node *b = graph_add_node(gra, "b");
	graph_node *c = graph_add_node(gra, "c");
	graph_node *d = graph_add_node(gra, "d");
	graph_node *e = graph_add_node(gra, "e");
	graph_node *f = graph_add_node(gra, "f");
			
	graph_add_edge(gra, a, b, 2);
	graph_add_edge(gra, a, c, 1);
	graph_add_edge(gra, a, d, 5);
	graph_add_edge(gra, b, c, 2);
	graph_add_edge(gra, b, d, 3);
	graph_add_edge(gra, c, d, 3);
	graph_add_edge(gra, c, e, 1);		
	graph_add_edge(gra, e, d, 1);
	graph_add_edge(gra, d, f, 5);		
	graph_add_edge(gra, e, f, 2);
		
	printf("Grafo:\n");
	graph_print(gra);
		
				
		

	// Test per cammini minimi
	printf("Distanze minime da tutti i nodi:\n");
	printf("\n");
	printf("Il tuo programma dovrebbe stampare:\n");
	printf("Distanze dal nodo a [c:1, e:2, d:3, f:4, b:2, a:0]\n");
	printf("Distanze dal nodo b [c:2, e:3, d:3, f:5, b:0, a:100000]\n");
	printf("Distanze dal nodo c [c:0, e:1, d:2, f:3, b:100000, a:100000]\n");
	printf("Distanze dal nodo d [c:100000, e:100000, d:0, f:5, b:100000, a:100000]\n");
	printf("Distanze dal nodo e [c:100000, e:0, d:1, f:2, b:100000, a:100000]\n");
	printf("Distanze dal nodo f [c:100000, e:100000, d:100000, f:0, b:100000, a:100000]\n");
	printf("\n");
	printf("Il tuo programma stampa:\n");
	distances(gra);
	printf("\n");
	
	return 0;
}
