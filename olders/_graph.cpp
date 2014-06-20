#include <iostream>
#include <stdlib.h> // Included to give access to atoi()
#include <fstream.h>
#include <string.h>

#define NUMNODES 8

using namespace std;

struct Node
{
	int		index;		// Numero do Nodo
	char	data[64];	// Algo armazenado no nodo
};

bool getNextLine(ifstream inF, char *line, int lineLen);

int main(void)
{
	Node		GraphNodes[NUMNODES];			// Array de nodos do grafo
	int			AdjMatrix[NUMNODES][NUMNODES];	// Matrix to define the graph links
	ifstream	inFile;
	char		line[81];
	int			i, j, idx, numLinks, link;


	// Initialize Adjacency Matrix to all 0s
	for(i=0; i<NUMNODES; i++)
		for(j=0; j<NUMNODES; j++)
			AdjMatrix[i][j] = 0;

	// Try to open the file with the graph data
    inFile.open("GraphData.txt", ifstream::in); 
    if(!inFile.is_open())
    {
        // inFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        cout << "Unable to open file graph.txt. \nProgram terminating...\n";
        return 0;
    }

	// Since we know ahead of time there will be 8 nodes in the graph we can
	// read and skip the line giving the number of nodes.
	getNextLine(inFile, line, 81);

	// Read all the graph data and build the adjacency matrix
	for(i=0; i<NUMNODES; i++)
	{
		// Read the graph ID and use this as it's index in the graph
		getNextLine(inFile, line, 81);
		idx = atoi(line);
		GraphNodes[idx].index = idx;

		// Read the graph string data and store it
		getNextLine(inFile, line, 81);
		strcpy(GraphNodes[idx].data, line);

		// Read the number of links for this node
		getNextLine(inFile, line, 81);
		numLinks = atoi(line);

		// Read all links and set the marker in the adjacency matrix
		for(j=0; j<numLinks; j++)
		{
			getNextLine(inFile, line, 81);  // Read next line
			link = atoi(line);				// Get link index
			AdjMatrix[idx][link] = 1;		// Set the link
		}
	}

	inFile.close();

	// Print data for testing ...
	for(i=0; i<NUMNODES; i++)
	{
		cout << "  " << GraphNodes[i].index << "        " << 
			GraphNodes[i].data << "\t";
		for(j=0; j<NUMNODES; j++)
		{
			if(AdjMatrix[i][j] == 1)
				cout << GraphNodes[j].index << "   ";
		}
		cout << "\n"; // end of line
	}

	for(i=0; i<NUMNODES; i++)
	{
		cout << i << "|";
		for(j=0; j<NUMNODES; j++)
		{
			cout << AdjMatrix[i][j] << "|";
		}
		cout << "\n +---------------+\n";
	}

	return(0);
}
