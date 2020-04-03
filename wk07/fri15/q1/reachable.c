
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void doReachable(Graph g, Vertex v, Set s);

Set reachable(Graph g, Vertex v) {
	Set s = SetNew();
	doReachable(g, v, s);
	return s;
}

// DFS
// visit vertex v
// perform DFS from vertex v
void doReachable(Graph g, Vertex v, Set s) {
	// how to 'visit' vertex v?
	SetAdd(s, v);
	// finding neighbours
	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && !SetContains(s, w)) {
			doReachable(g, w, s);
		}
	}
}
