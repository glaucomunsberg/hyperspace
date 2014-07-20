#ifndef GRAPHTBB_H
#define	GRAPHTBB_H
#include <string>
#include <algorithm>
#include "tbb/blocked_range.h"
#include "tbb/parallel_for.h"
#include "tbb/task_scheduler_init.h"

using namespace std;

class GraphTBB: public Graph{
public:

	GraphTBB(){}
	~GraphTBB(){}
	/*
	void operator()( const tbb::blocked_range<size_t>& r ) const {
        for( size_t i=r.begin(); i!=r.end(); ++i ) {
           insertList(i);
        }
    }
*/
	void insertEdges(int adj1, int adj2, int value);
	void removeEdges(int adj1, int adj2);
	void checkAdjacencies(Adjacency *tmpAdjacency, int thread);
	void minimumWeightSpanningTree();
	void insertList(int a);
};
#endif	/* GRAPHTBB_H */
