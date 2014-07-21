#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "../Graph.hpp"
#include "GraphTBB.hpp"
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"
#include <vector>
using namespace std;


class Check {
	vector<Adjacency> adjacencies;
	vector<Adjacency> minimumAdjacencies;
	vector<Node> edges;
	int * cont;
public:
	void operator() ( const blocked_range<size_t>& r ) const {
		for ( size_t i = r.begin(); i != r.end(); ++i ) {
			int change;
			int removePosition;

			if(edges[tmpAdjacency->node1].tree != edges[tmpAdjacency->node2].tree){
			
				minimumAdjacencies.push_back(Adjacency(tmpAdjacency->node1,tmpAdjacency->node2,tmpAdjacency->value));
				change = edges[tmpAdjacency->node2].tree;
				for(int a=0; a < (int) edges.size(); a++){
				
					if(edges[a].tree == change){
						edges[a].tree = edges[tmpAdjacency->node1].tree;
					}
				}
			}
		}
	}
	/*
	Check(){};
	Check(vector<Adjacency> & a, vector<Node> & e, vector<Adjacency> & m , int c)
		tmpAdjacency(a), edges(e),  minimumAdjacencies(m)  cont(c){ }
	*/
	Adjacency Check::getAdjacencies(){

		return adjacencies;
	}
	
	Adjacency Check::getMinimumAdjacencies(){

		return minimumAdjacencies;
	}	
	Node Check::getEdges(){

		return edges;
	}
	int Check::getCont(){

		return cont;
	}

};