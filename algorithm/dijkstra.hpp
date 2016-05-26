//relajacion
void relajacion( int actual , int adyacente , int peso){
	//Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
	if( distancia [actual] + peso < distancia [adyacente]){
		distancia[adyacente] = distancia [actual] + peso; //relajamos el vertice actualizando la distancia
		previo[adyacente] = actual; //actualizamos el v.previo
		Q.push( Node(adyacente , distancia [adyacente]) );//agregamos adyacente a la cola prioridad
	}
}

void dijkstra (int inicial){
	init(); //inicializamos arreglos
	Q.push( Node( inicial , 0) ); //Insertamos el vértice inicial en la priority queue
	distancia[inicial] = 0; //dist.ini = 0
	int actual, adyacente, peso, destino;
	while ( !Q.empty() ){
		actual = Q.top().first;
		Q.pop();
		if( visitado[actual] ) continue; //Si el vértice es visitado sigo en la cola
		visitado[actual] = true; //visitado

		//reviso adyacentes
		for( int i=0 ; i<ady[actual].size() ; ++i){
			adyacente = ady[actual][i].first; //id del vertice adyacente
			peso = ady[actual][i].second; //peso de la arista que uno actual con adyacente
			if( !visitado[adyacente] ){
				relajacion(actual, adyacente, peso);
			}
		}

	}

	cout << "Distancias mas cortas iniciando en vertice " << inicial << endl;
	for( int i=1 ; i<=V ; ++i){
		cout << "Vertice "<<i<<", distancia mas corta = "<<distancia[i]<<endl;
	}

	puts("IMPRESION");
	cout<<"Ingrese vertice destino: "<<endl;
	cin >> destino;
	print(destino);
	cout<<endl;

}