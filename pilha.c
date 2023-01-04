#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
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
	
	FILE *fptr;
	
	if ( (fptr = fopen("pilha.txt", "w+")) == NULL){
		fprintf(stderr, "Could not open file");
	}
	
	while(no){
		printf("%d " , no->valor);
		fprintf(fptr, "%d " , no->valor);
		no = no ->proximo;
	}
	
}

int main (){
	
	
	
	No *r, *no, *topo = NULL;
	FILE *fptr;
	int valor, i, opcao;
	
	if ( (fptr = fopen("pilha.txt", "w+")) == NULL){
		fprintf(stderr, "Could not open file");
	
	}
	
do{
	
	printf("\n\t0 - Sair\n\t1 - Inserir no Topo\n\t2 - Remover do Topo\n\t3 - Imprimir e Registrar no Arquivo\n\t");
	scanf("%d" , &opcao);
	
	switch(opcao){
		
		case 1:
			printf("Insira um numero na pilha\n");
			scanf("%d" , &valor);
			push(&topo ,valor);
			break;
		
		case 2:
			printf("Removendo topo da pilha...\n");
			r = pop(&topo);
			break;
		
		case 3:
			imprimir(topo);
			printf("\n");
			break;
			
		default:
			
			if(opcao != 0){
				printf("Opcao Invalida\n");
			}
		
				
		}
		
} while(opcao != 0);

	
	fclose(fptr);
	
	return 0;
}
