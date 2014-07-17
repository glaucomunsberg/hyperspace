#ifndef GRAPHORIGINAL_H
#define	GRAPHORIGINAL_H
#include <string>
#include <algorithm>
using namespace std;

class GraphOriginal: public Graph{
public:

	GraphOriginal(){}
	~GraphOriginal(){}
	
	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void checkAdjacencies(Adjacency *tmpAdjacency, int thread);
	void minimumWeightSpanningTree();
};
#endif	/* GRAPHORIGINAL_H */
