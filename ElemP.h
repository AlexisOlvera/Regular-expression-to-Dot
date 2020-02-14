typedef char Elem;

void ImpElem(Elem e){
	printf("%c", e);
}

int Prec(char c){
	switch(c){
		case '.':return 1;
		case '|':return 2;
		case '(': case ')': return 3; 
	}
}

int EsCerradura(char c){
	return c == '+' || c == '*';
}

int EsParI(char c){
	return c == '(';
}

int EsParD(char c){
	return c == ')';
}

int EsLetra(char c){
	return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

int EsOperandoOInfijo(char c){
	return EsCerradura(c) || EsLetra(c);
}

int EsOperador(char c){
	if( c  == '.' || c == '|')
		return 1;
	else
		return 0;
}
