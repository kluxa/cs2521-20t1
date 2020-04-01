
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void doReachable(Graph g, Vertex v, Set s, int *visited);

Set reachable(Graph g, Vertex v) {
	Set s = SetNew();
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	doReachable(g, v, s, visited);
	free(visited);
	return s;
}

// DFS
void doReachable(Graph g, Vertex v, Set s, int *visited) {
	visited[v] = 1;
	SetAdd(s, v);
	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && visited[w] == 0) {
			doReachable(g, w, s, visited);
		}
	}
}
