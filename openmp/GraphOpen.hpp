#ifndef GRAPHOPEN_H
#define	GRAPHOPEN_H
#include <string>

using namespace std;

class GraphOpen: public Graph{
public:

	GraphOpen(){}
	~GraphOpen(){}

	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void minimumWeightSpanningTree();
	void checkAdjacencies();
};
#endif	/* GRAPHOPEN_H */
