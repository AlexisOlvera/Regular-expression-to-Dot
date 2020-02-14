 typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
} *Pila;

Pila empty(){
	return NULL;
}

Pila push(Elem e, Pila p){
	Pila r = (Pila)malloc(sizeof(struct Nodo));
	r -> dato = e;
	r -> sig = p;
	return r;
}

int isempty(Pila p){
	return p == NULL;
}

Elem top(Pila p){
	return p -> dato;
}

Pila pop(Pila p){
	return p -> sig;
}
