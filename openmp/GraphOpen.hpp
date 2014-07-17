#ifndef GRAPHOPEN_H
#define	GRAPHOPEN_H
#include <string>
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/omp.h>

using namespace std;

class GraphOpen: public Graph{
public:

	
	omp_lock_t lock;
	GraphOpen(){
		omp_init_lock(&lock);
	}
	~GraphOpen(){
		omp_destroy_lock(&lock);
	}
	
	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void minimumWeightSpanningTree();
	void checkAdjacencies(Adjacency *tmpAdjacency, int thread);
};
#endif	/* GRAPHOPEN_H */
