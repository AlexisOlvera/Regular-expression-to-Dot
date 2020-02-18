typedef struct afn {
	Estado inicio;
	Estado final;
} * AFN;

AFN afnEmpty(){
	return NULL;
}

AFN afnSimbolo(char a){
	AFN nuevo = (AFN) malloc(sizeof(struct afn));
	Estado final = estadoFinal();
	Estado inicio = crearEstado(a, final, '0', estadoEmpty());
	nuevo -> inicio = inicio;
	nuevo -> final = final;
	return nuevo;
}

AFN concatenarAFN(AFN a, AFN b){
	AFN nuevo = (AFN) malloc(sizeof(struct afn));
	a -> final = b -> inicio;
	nuevo -> inicio = a -> inicio;
	nuevo -> final = b -> final;
	return nuevo;
}

AFN unionAFN(AFN a, AFN b){
	AFN nuevo = (AFN) malloc(sizeof(struct afn));
	Estado inicio = crearEstado('E', a->inicio, 'E', b->inicio);
	Estado final = estadoFinal();
	a -> final -> siguiente1 = final;
	a -> final -> transicion1 = 'E';
	b -> final -> siguiente1 = final;
	b -> final -> transicion1 = 'E';
	nuevo -> inicio = inicio;
	nuevo -> final = final;
	return nuevo;
}

AFN positivaAFN(AFN a){
	AFN nuevo = (AFN) malloc(sizeof(struct afn));
	Estado inicio = crearEstado('E', a->inicio, '0', estadoEmpty());
	Estado final = estadoFinal();
	a -> final -> siguiente1 = final;
	a -> final -> transicion1 = 'E';
	a -> final -> siguiente2 = a->inicio;
	a -> final -> transicion2 = 'E';
	nuevo -> inicio = inicio;
	nuevo -> final = final;
	return nuevo;
}

AFN kleenAFN(AFN a){
	AFN nuevo = (AFN) malloc(sizeof(struct afn));
	Estado inicio = crearEstado('E', a->inicio, 'E', a->final);
	Estado final = estadoFinal();
	a -> final -> siguiente1 = final;
	a -> final -> transicion1 = 'E';
	a -> final -> siguiente2 = a->inicio;
	a -> final -> transicion2 = 'E';
	nuevo -> inicio = inicio;
	nuevo -> final = final;
	return nuevo;
}