#ifndef GRAPH_H
#define	GRAPH_H

#include <string>
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

struct lessThanKey
{
    inline bool operator() (const Adjacency& struct1, const Adjacency& struct2)
    {
        return (struct1.value < struct2.value);
    }
};

class Graph{

protected:
	vector<Adjacency> adjacencies;
	vector<Adjacency> minimumAdjacencies;
	vector<Node> edges;
	int **matrix;
	int sizeGraph;

public:
	Graph();
	~Graph();
	
	int getSize();
	void printMatrix();
	void printMinimumWeightSpanningTree();
	void inicialize();
	void openFile(string fileName);
	void setSize(int size);

	virtual void minimumWeightSpanningTree()=0;
	virtual void insertEdges(int adj1, int adj2, int value)=0;	
	virtual void removeEdges(int adj1, int adj2)=0;
};

#endif	/* GRAPH_H */