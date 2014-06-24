#ifndef GRAPH_H
#define	GRAPH_H

#include <string>
#include <vector>

using namespace std;
struct edges
{
	int nodo1;
	int nodo2;
	int value;
};
class Graph{

public:
	vector<edges> edges;
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
	virtual bool existEdges(int adj1, int adj2)=0;
};


#endif	/* GRAPH_H */