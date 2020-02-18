#include<stdio.h>
#include<stdlib.h>
#include "ElemP.h"
#include "Pila.h"
#include "Estados.h"
#include "AFN.h"

int main(){
	
	char *in = "(a+.b)*|(a.c.(a|b+))*";

	//Convierte el texto de infijo a posfijo
	int i = 0;
	Pila op = empty();
	Pila pos = empty();
	while(in[i] !='\0'){
		if(EsLetra(in[i]) || EsCerradura(in[i])){
			ImpElem(in[i]);	
			pos = push(in[i], pos);
		}else{
			if(EsParI(in[i]))
				op=push(in[i],op);
			else 
				if (EsParD(in[i])){
					while(!EsParI(top(op))){
						ImpElem(top(op));
						pos = push(top(op), pos);
						op=pop(op);
					}
					op=pop(op);
				}
				else
					if(isempty(op))
						op=push(in[i],op);
					else
						if(EsParI(top(op)))
							op=push(in[i], op);
						else{
							while(Prec(in[i]) <= Prec(top(op)) && !EsParI(top(op))){
								ImpElem(top(op));
								pos = push(top(op), pos);
								op=pop(op);
							}
							op=push(in[i], op);
						}	
		}	
		i++;
	}
	while(!isempty(op)){
		ImpElem(top(op));
		pos = push(top(op), pos);
		op = pop(op);
	}
	i=0;
	int final = -1, inicio = 0;
	while(i<=0){
		switch(top(pos)){
			case '|':
				printf("%d -> {%d, %d} [label = \"&epsilon;\"];\n", inicio, i++, ++i);
				inicio = i-1;
				printf("{%d, %d} -> %d [label = \"&epsilon;\"];\n", i++, ++i, final);
				final = i-1;
				break;
			case '+':
				printf("%d -> %d [label = \"&epsilon;\"]; \n", inicio, ++i);
				inicio = i;
				printf("%d -> %d [label = \"&epsilon;\"]; \n", ++i, inicio);
				printf("%d -> %d [label = \"&epsilon;\"]; \n", ++i, final);
				final = i-1;
				break;
			case '*':
				printf("\n");
				break;
		}
		if(!final)
			final=i;
	}

	while(!isempty(pos)){
		ImpElem(top(pos));
		pos = pop(pos);
	}
	printf(" \n");	
	return 0;
}

