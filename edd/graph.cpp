
#include <iostream>
//#include <vector>
#include <queue>

using namespace std;

#define MAX 10005 //máximo número de vértices
#define Node pair < int , int > //par(first, second) first vertice adyacente y second peso arista
#define INF 1<<30 //valor grande para la distancia inicial

//Comparador min-heap
struct cmp
{
	bool operator() ( const Node &a , const Node &b){
		return a.second > b.second;
	}
};

vector < Node > ady[ MAX ]; //lista de adyacencia
int distancia[ MAX ]; //distancia desde v.inicial a v.id
bool visitado[ MAX ]; //vertice visitado
priority_queue< Node , vector<Node> , cmp > Q; //queue de c++. usamos cmp implementado arriba para que menor valor en tope
int V; //numero de vertices
int previo[ MAX ]; //impresion de caminos

//inicializacion del grafo
void init(){
	for ( int i=0 ; i<=V ; ++i){
		distancia[i] = INF; //todas las distancias INF
		visitado[i] = false; //no visitado
		previo[i] = -1; //valor -1 para previo
	}
}

//Impresion
void print( int destino ){
	if( previo[destino] != -1) //Existe v.previo
		print( previo[destino]); //recursivo exploro
	cout << destino << " ";
}



















