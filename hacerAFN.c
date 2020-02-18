#include<stdio.h>
#include<stdlib.h>
#include "Estados.h"
#include "AFN.h"
#include "pilaAFN.h"
int main(){
	char *pos = "a+b.*ac.ab+|.*|";
	Pila pila = empty();
	AFN tmp, a, b;
	int i=0;
	while(pos[i] != '\0'){
		if(pos[i] >= 'a' && pos[i] <= 'z'){
			tmp=afnSimbolo(pos[i]);
			pila = push(tmp, pila);
		} else{
			switch(pos[i]){
				case '.':
					a = top(pila);
					pila = pop(pila);
					b = top(pila);
					pila = pop(pila);
					tmp = concatenarAFN(a, b);
					pila  = push(tmp, pila);
					break;
				case '|':
					a = top(pila);
					pila = pop(pila);
					b = top(pila);
					pila = pop(pila);
					tmp = unionAFN(a, b);
					pila  = push(tmp, pila);
					break;
				case '+':
					a = top(pila);
					pila = pop(pila);
					tmp = positivaAFN(a);
					pila  = push(tmp, pila);
					break;
				case '*':
					a = top(pila);
					pila = pop(pila);
					tmp = kleenAFN (a);
					pila  = push(tmp, pila);
					break;
			}
		}
		i++;
	}
}