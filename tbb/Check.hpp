#ifndef GRAPHCHECK_H
#define	GRAPHCHECK_H

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

class Adjacency
{
public:
	int node1;
	int node2;
	int value;
	Adjacency(){}
	Adjacency(int nod1, int nod2, int val){

		node1 = nod1;
		node2 = nod2;
		value = val;
	}

	Adjacency(Adjacency const& copy){
		node1 = copy.node1;
		node2 = copy.node2;
		value = copy.value;
	}
};

class Node{
public:
	int value;
	int tree;

	Node(int val,int arv){

		value = val;
		tree = arv;
	}
};
class Check {
	vector<Adjacency> tmpAdjacency;
	vector<Adjacency> minimumAdjacencies;
	vector<Node> edges;
	int * cont;
public:

	Check(){};
	Check(vector<Adjacency> & a, vector<Node> & e, vector<Adjacency> & m , int * c) :
		tmpAdjacency(a), edges(e),  minimumAdjacencies(m),  cont(c){ }

	Adjacency getAdjacencies();
	Adjacency getMinimumAdjacencies();	
	Node getEdges();
	int getCont();
};
#endif
