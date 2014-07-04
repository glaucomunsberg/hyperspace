#ifndef GRAPHCILK_H
#define	GRAPHCILK_H
#include <string>
#include <mutex>
#include <algorithm>
using namespace std;

class GraphCilk: public Graph{
public:

	GraphCilk(){}
	~GraphCilk(){}
	std::mutex mtx;
	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void checkAdjacencies();
	void minimumWeightSpanningTree();
};
#endif	/* GRAPHCILK_H */
