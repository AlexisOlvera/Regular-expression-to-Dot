typedef struct estado {
	struct estado *siguiente1;
	struct estado *siguiente2;
	char transicion1;
	char transicion2;
} * Estado;

Estado estadoEmpty(){
	return NULL;
}

Estado estadoFinal(){
	Estado nuevo = (Estado) malloc(sizeof(struct estado));
	nuevo -> transicion1 = '0';
	nuevo -> siguiente1 = estadoEmpty();
	nuevo -> transicion2 = '0';
	nuevo -> siguiente2 = estadoEmpty();
}

Estado crearEstado(char a, Estado est1, char b, Estado est2){
	Estado nuevo = (Estado) malloc(sizeof(struct estado));
	nuevo -> transicion1 = a;
	nuevo -> siguiente1 = est1;
	nuevo -> transicion2 = b;
	nuevo -> siguiente2 = est2;
	return nuevo;
}