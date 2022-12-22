#include <stdlib.h>
#include <stdio.h>

struct Fila
{
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 
};

//Criando a fila
void criaFila(struct Fila *fi, int c)
{ 
	fi->capacidade = c;
	fi->dados = (float*) malloc(fi->capacidade * sizeof(float));
	fi->primeiro = 0;
	fi->ultimo = -1;
	fi->nItens = 0; 
}

//Adicionando os elemntos na fila
void inserir(struct Fila *fi, int v)
{
	if(fi->ultimo == fi->capacidade-1)
		fi->ultimo = -1;
	fi->ultimo++;
	fi->dados[fi->ultimo] = v;
	fi->nItens++;
}

//Removendo o primeiro elemento da fila
int remover( struct Fila *fi )
{ 
	int temp = fi->dados[fi->primeiro++];
	if(fi->primeiro == fi->capacidade)
		fi->primeiro = 0; 
  
	fi->nItens--;
	return temp; 
}

//Olhando se tem itens na fila
int estaVazia( struct Fila *fi )
{ 
	return (fi->nItens==0); 
}

//Olhando se a fila está cheia
int estaCheia( struct Fila *fi )
{ 
	return (fi->nItens == fi->capacidade);
}

//Olhando os elementos da fila
void mostrarFila(struct Fila *fi)
{
	int cont, i;

	for ( cont=0, i= fi->primeiro; cont < fi->nItens; cont++)
  {
		printf("%.2f\t",fi->dados[i++]);
		if (i == fi->capacidade)
			i=0; 
	}
	printf("\n\n"); 
}

int main()
{
	int opcao, capa;
	float valor;
	struct Fila umaFila;
  struct Fila copia;

	//Criando a fila
	printf("\nDigite a capacidade da fila: \n");
	scanf("%d",&capa);
	criaFila(&umaFila, capa);
  printf("\n  A fila tem tamanho máximo de %d itens\n", capa);

	//Opções
	while( 1 ){
		printf("\n0 - Para sair\n1 - Para adicionar no final da fila\n2 - Para remover do começo da fila\n3 - Para olhar os itens da fila\n4 - Para fazer uma copia da fila\n5 - Para olhar a copia da fila\n\nDigite: ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: 
				if (estaCheia(&umaFila)){
					printf("\nA fila já está cheia! \n\n");
				}
				else {
					printf("\nAdicione um item: ");
					scanf("%fi", &valor);
					inserir(&umaFila,valor);
          printf("\n%f foi adicionado.\n\n", valor) ;
				}
				break;

			case 2: 
				if (estaVazia(&umaFila)){
					printf("\nA fila está vazia!\n\n");
				}
				else {
					valor = remover(&umaFila);
					printf("\n%f foi removido.\n\n", valor) ; 
				}
				break;

				case 3:
					if (estaVazia(&umaFila)){
						printf("\nA fila está vazia!\n\n");
					}
					else {
						printf("\nFila original: ");
						mostrarFila(&umaFila);
					}
					break;

        case 4:
          copia = umaFila;
          printf("\nFila copiada.\n");
          break;

      case 5:
          if (estaVazia(&copia)){
						printf("\nA fila está vazia!\n\n");
					}
					else {
						printf("\nCopia da fila: ");
						mostrarFila(&copia);
					}
					break;

				default:
					printf("\nOpção não existe!! \nPor favor digite um número da lista abaixo: \n\n");
		}
	}
}