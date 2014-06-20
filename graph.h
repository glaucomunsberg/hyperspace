#ifndef GRAPH_H
#define	GRAPH_H

#include <string>

using namespace std;
class Graph{

protected:
	static int **matrix;
	static int sizeGraph;
	void inicialize();
	void openFile(string const &fileName);
	void setSize(int size);
public:
	Graph();
	~Graph();
	virtual void insertAdj(int adj1, int adj2)=0;
	virtual void removeAdj(int adj1, int adj2)=0;
	virtual void existAdj(int adj1, int adj2)=0;
	int getSize();

};


#endif	/* GRAPH_H */