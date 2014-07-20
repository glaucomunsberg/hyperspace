#ifndef GRAPHCPP11_H
#define	GRAPHCPP11_H
#include <string>
#include <algorithm>
#include <mutex>
using namespace std;

class GraphCpp11: public Graph{
public:


	std::mutex mutex;
	GraphCpp11(){}
	~GraphCpp11(){}
	
	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void checkAdjacencies(Adjacency *tmpAdjacency, int thread);
	void minimumWeightSpanningTree();
};
#endif	/* GRAPHCPP11_H */
