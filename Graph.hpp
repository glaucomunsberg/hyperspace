#ifndef GRAPH_H
#define	GRAPH_H

#include <string>
#include <vector>

using namespace std;
class Adjacency
{
public:
	int nodo1;
	int nodo2;
	int value;
	bool ative;
	Adjacency(int nod1, int nod2, int val){
		nodo1 = nod1;
		nodo2 = nod2;
		value = val;
		ative = false;
	}
};

class Nodo{
public:
	int value;
	int tree;
	Nodo(int val,int arv){
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
	vector<Nodo> edges;
	int **matrix;
	int sizeGraph;

public:
	Graph();
	~Graph();
	
	int getSize();
	void printMatrix();
	void inicialize();
	void openFile(string fileName);
	void setSize(int size);

	virtual void insertEdges(int adj1, int adj2)=0;	
	virtual void removeEdges(int adj1, int adj2)=0;
	virtual void sortedEdges()=0;
	virtual bool existEdges(int adj1, int adj2)=0;

};


#endif	/* GRAPH_H */