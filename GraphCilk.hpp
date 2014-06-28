#ifndef GRAPHCILK_H
#define	GRAPHCILK_H
#include <string>

using namespace std;

class GraphCilk: public Graph{
public:

	GraphCilk(){}
	~GraphCilk(){}

	void insertEdges(int adj1, int adj2);
	void removeEdges(int adj1, int adj2);
	void minimumWeightSpanningTree();
};
#endif	/* GRAPHCILK_H */