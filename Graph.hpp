#ifndef GRAPH_H
#define	GRAPH_H

#include <string>
#include <vector>

using namespace std;
struct Adjacency
{
	int nodo1;
	int nodo2;
	int value;
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