#ifndef GRAPH_H
#define	GRAPH_H

#include <string>

using namespace std;
class Graph{

public:
	
	void inicialize();
	void openFile(string fileName);
	void setSize(int size);

	Graph();
	~Graph();
	int **matrix;
	int sizeGraph;

	virtual void insertAdj(int adj1, int adj2)=0;
	virtual void removeAdj(int adj1, int adj2)=0;
	virtual bool existAdj(int adj1, int adj2)=0;
	virtual void printMatrix()=0;
	int getSize();

};


#endif	/* GRAPH_H */