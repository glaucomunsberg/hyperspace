#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string>
#include "../Graph.hpp"
#include "GraphCpp11.hpp"
#include <thread>

using namespace std;

void GraphCpp11::insertEdges(int adj1, int adj2, int value){

	matrix[adj1][adj2] = value;
}

void GraphCpp11::removeEdges(int adj1, int adj2){

	if(matrix[adj1][adj2] > 0){

		matrix[adj1][adj2]--;
	}
}



void GraphCpp11::minimumWeightSpanningTree(){
	
	for(int a =0;a < getSize(); a++){	
		edges.push_back(Node(a,a));
		for(int b =0; b < getSize(); b++){
			if(matrix[a][b] != 0){
				adjacencies.push_back(Adjacency(a,b,matrix[a][b]));
			}
		}
	}
	

	std::sort(adjacencies.begin(), adjacencies.end(), lessThanKey());
	
	// zera o vetor
	int cont[1000000];
	int j = 0;
	for(int i = 0; i < 1000000; i++){
		cont[i] = 0;
	}

	// cria um vetor de pesos
	// cara posicao deste vetor possui um contador de arestas para cada gerar o vetor de threads
	int anterior = adjacencies.at(0).value;
	for(int i = 1; i < adjacencies.size(); i++){
		if(adjacencies.at(i).value == anterior){
			 cont[j] = cont[j]++;
		} else {
			anterior = adjacencies.at(i).value;
			j++;
		}
	}
	
	
	int idThread = 0;
	Adjacency *tmp1Adjacency;
	Adjacency *tmp2Adjacency;
	
	int u = 0; // contador para verificar a posicao do vetor de threads
	while(!adjacencies.empty()){

		tmp1Adjacency = new Adjacency(adjacencies.at(0).node1,adjacencies.at(0).node2,adjacencies.at(0).value);
		checkAdjacencies(tmp1Adjacency,idThread);
		idThread++;
		adjacencies.erase(adjacencies.begin());
		
		

		if(!adjacencies.empty()){
			tmp2Adjacency = new Adjacency(adjacencies.at(0).node1,adjacencies.at(0).node2,adjacencies.at(0).value);
			int valuePivo = tmp1Adjacency->value;
			int valueOuther = tmp2Adjacency->value;
			
			std::thread t[cont[u]]; // a cada passada do while, ele cria um vetor de threads, referente a quantidade de arestas com o mesmo peso.
			// lembrnado que o vetor cont possui a quantidade de arestas que cada peso tem

			int i=0; // contador de threads
			while(valuePivo == valueOuther){
				// instancia a thread 
				// t[i] significa que cada aresta será uma thread
				t[i] = std::thread(&GraphCpp11::checkAdjacencies, this, tmp2Adjacency,idThread);
				idThread++;
				adjacencies.erase(adjacencies.begin());
				
				if(!adjacencies.empty()){
					tmp2Adjacency = &adjacencies.at(0);
					valueOuther = tmp2Adjacency->value;

				}else{
					valueOuther = valuePivo+1;
				}
			i++;
			}

			// executa todos os joins do vetor de threads
			for (int j = 0; j < cont[u]; j++){
				t[j].join();
			}
		}
		u++;
	}
}

void GraphCpp11::checkAdjacencies(Adjacency *tmpAdjacency, int thread){
	
	
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

int main(int argc, char* argv[]) {

	cout << "Graph->GraphCpp11()" << endl;
	
	Graph *graph;
	graph = new GraphCpp11();
	std::string file = "";


	graph->setSize(2);
	graph->inicialize();

	if(argc <= 1){

		file = "graphExample.txt";
	}else{

		file = argv[1];
		
	}

	graph->openFile(file);
	graph->printMatrix();
	graph->minimumWeightSpanningTree();
	graph->printMinimumWeightSpanningTree();
	
	return 0;
}
