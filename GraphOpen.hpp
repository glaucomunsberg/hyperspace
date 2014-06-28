#ifndef GRAPHOPEN_H
#define	GRAPHOPEN_H
#include <string>

using namespace std;

class GraphOpen: public Graph{
public:

	GraphOpen(){}
	~GraphOpen(){}

	void insertEdges(int adj1, int adj2);
	void removeEdges(int adj1, int adj2);
	void minimumWeightSpanningTree();
};
#endif	/* GRAPHOPEN_H */