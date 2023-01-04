#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct No{
	int valor;
	struct NODO *prox;
} no;

no hash_table[19];

void inicializarTabela(){
    int i;
    for(i = 0; i < 19; i++)
        hash_table[i].valor = -1;
}

int gerarCodigoHash(int chave){
    return chave % 19;
}

void inserir(no no){
    int indice = gerarCodigoHash(no.valor);
    while(hash_table[indice].valor != -1)
        indice = gerarCodigoHash(indice + 1);
    hash_table[indice] = no;
}

no * buscar(int chave){
    int indice = gerarCodigoHash(chave);
    while(hash_table[indice].valor != -1){
        if(hash_table[indice].valor == chave)
            return &hash_table[indice];
        else
            indice = gerarCodigoHash(indice + 1);
    }
    return NULL;
}

void imprimir(){
    int i;
    printf("\n\n-- Tabela --\n\n");
    for(i = 0; i < 19; i++){
        if(hash_table[i].valor != -1)
            printf("%2d = %2d\n", i, hash_table[i].valor);
        else
            printf("%2d =\n", i);
    }
    printf("\n\n------------\n\n");
}

void criarTabelaArquivo(FILE * file){
	file = fopen("Hash_nums.txt", "r");
	char arquivo_linha[20];
	
	if(file == NULL){
		printf("ERRO!!");
	} else {
		inicializarTabela();
		while(fgets(arquivo_linha, 20, file) != NULL){
			no no;
			no.valor = atoi(arquivo_linha);
			inserir(no);
		}
  			
	}
	
	fclose(file);
}


int main() {
	
    int op, chave;
    no * no;
    int valor;
    FILE * file;

    inicializarTabela();

    do{
		system("cls");
    	printf("-- Menu --\n\n");
        printf("1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Criar tabela via arquivo de texto\n0 - Sair\n");
        printf("----------\nOpcao: ");
        scanf("%d", &op);

        switch(op){
        case 0:
            printf("\n\nSaindo...\n");
            break;
        case 1:
        	printf("\n\nEntre com o valor a ser inserido na tabela: ");
        	scanf("%d", &valor);
            inserir(valor);
            printf("\nValor inserido!\n");
            getch();
            break;
        case 2:
            printf("\n\nDigite o valor a ser buscado: ");
            scanf("%d", &chave);
            no = buscar(chave);

            if(no){
                printf("\nValor encontrado %d na tabela!\n", no->valor);
                getch();
			}
            else{
                printf("\nValor n�o encontrado!\n");
                getch();
			}
            break;
        case 3:
            imprimir();
            getch();
            break;
        case 4:
            criarTabelaArquivo(file);
            imprimir();
            getch();
            break;
        default:
            printf("\n\nOpcao invalida!\n");
            getch();
        }

    }while(op != 0);

    return 0;
}
