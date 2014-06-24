#ifndef GRAPH_H
#define	GRAPH_H

#include <string>
#include <vector>

using namespace std;
struct edge
{
	int nodo1;
	int nodo2;
	int value;
};

struct less_than_key
{
    inline bool operator() (const edge& struct1, const edge& struct2)
    {
        return (struct1.value < struct2.value);
    }
};

class Graph{

public:
	vector<edge> edges;
	int **matrix;
	int sizeGraph;

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