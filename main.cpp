//
//  main.cpp
//  Graphv1
//
//  Created by Tal Zeev Torres on 23/05/16.
//  Copyright © 2016 Tal Zeev Torres. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "edd/graph.cpp"
#include "algorithm/dijkstra.hpp"

using namespace std;

int main(){
	int E, origen, destino, peso, inicial;
	string line;
	ifstream myfile("graph.txt");
	if( myfile.is_open()){
		myfile >> V >> E;
		cout << "Vertices: " << V << endl;
		cout << "Aristas: " << E << endl;
		puts("orig dest pes");
		while(E--){
			myfile >> origen>>destino>>peso;
			ady[origen].push_back( Node( destino, peso) );  //grafo dirigido
			//ady[origen].push_back( Node( origen, peso) ); //grafo no dirigido
			cout << origen<<"     "<<destino<<"     "<<peso<<endl;
		}

		myfile >> inicial;
		dijkstra(inicial);
		myfile.close();
	}

	else cout << "Unable to open file"<<endl;
	return 0;
}