#include <stdio.h>
#include <stdlib.h>



typedef struct no{
	char valor;
	struct no *proximo;
}No;

No* criaPilha(int num){
	No* novo = (No*)malloc(sizeof(No));
	
	novo->valor = num;
	novo->proximo = NULL;
	
	return novo;
}

No* push(No **topo, int num){
	No *novo;
	
	if(*topo == NULL){
		novo = criaPilha(num);
		*topo = novo;
	}
	else{
		novo = criaPilha(num);
		novo->proximo = *topo;
		*topo = novo;
	}
	
	return novo;
}

No* pop(No **topo){
	No *remover;
	
	if(*topo){
		remover = *topo;
		*topo = remover->proximo;
	}
	else{
		printf("Pilha vazia\n");
	}
	
	return remover;
}


void imprimir(No *no){
	
	
	
	while(no){
		printf("%d " , no->valor);
		no = no ->proximo;
	}
	
}

No * somapilha(No * topo){
	No * aux = NULL;
	char charsoma;
	int soma, char1, char2;
	
	push(&aux, topo->valor);
	pop(&topo);
	
	if(topo->valor != 43){
		printf("Erro ao Somar\n");
		return topo;
	}
	else{
		pop(&topo);
		char1 = topo->valor;
		char2 = aux ->valor;
		soma = char1 + char2 - 48;
		charsoma = soma;
		pop(&topo);
		push(&topo, charsoma);
		return topo;
	}
}

No * subpilha(No * topo){
	No * aux = NULL;
	char charsoma;
	int soma, char1, char2;
	
	push(&aux, topo->valor);
	pop(&topo);
	
	if(topo->valor != 45){
		printf("Erro ao Somar\n");
		return topo;
	}
	else{
		pop(&topo);
		char1 = topo->valor;
		char2 = aux ->valor;
		soma = char1 + char2 + 48;
		charsoma = soma;
		pop(&topo);
		push(&topo, charsoma);
		return topo;
	}
}

No * multpilha(No * topo){
	No * aux = NULL;
	char charsoma;
	int soma, char1, char2;
	
	push(&aux, topo->valor);
	pop(&topo);
	
	if(topo->valor != 42){
		printf("Erro ao Somar\n");
		return topo;
	}
	else{
		pop(&topo);
		char1 = topo->valor - 48;
		char2 = aux ->valor - 48;
		soma = (char1*char2);
		charsoma = soma + 48;
		pop(&topo);
		push(&topo, charsoma);
		return topo;
	}
}

No * divpilha(No * topo){
	No * aux = NULL;
	char charsoma;
	int soma, char1, char2;
	
	push(&aux, topo->valor);
	pop(&topo);
	
	if(topo->valor != 47){
		printf("Erro ao Somar\n");
		return topo;
	}
	else{
		pop(&topo);
		char1 = topo->valor - 48;
		char2 = aux ->valor - 48;
		soma = (char1/char2);
		charsoma = soma + 48;
		pop(&topo);
		push(&topo, charsoma);
		return topo;
	}
}

int main (){
	
	
	
	No *topo = NULL;
	FILE *fptr;
	char exp[1000];
	int valor, i, opcao;
	
	if ( (fptr = fopen("CalcPilha.txt", "r")) == NULL){
		fprintf(stderr, "Could not open file");
	}
	
	
	while(fgets(exp, 1000, fptr) != NULL){
		push(&topo, *exp);
	}
	
	
	
	
	fclose(fptr);
	
	return 0;
}
