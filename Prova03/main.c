#include <stdlib.h>
#include <stdio.h>

struct Fila{
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; };

//Criando a fila:
void criarFila(struct Fila *f, int c){ 
	f->capacidade = c;
	f->dados = (float*) malloc(f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; }

//Inserindo um elemento por vez na fila:
void inserir(struct Fila *f, int v){
	if(f->ultimo == f->capacidade-1){
		f->ultimo = -1;}
	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++; }

//Removendo elementos da fila (sempre pegando o primeiro item):
int remover( struct Fila *f ){ 
	int temp = f->dados[f->primeiro++];
	if(f->primeiro == f->capacidade){
		f->primeiro = 0; }
  
	f->nItens--;
	return temp; }

//Verificando se a fila está vazia:
int estaVazia( struct Fila *f ){ 
	return (f->nItens==0); }

//Verificando se a filha está cheia:
int estaCheia( struct Fila *f ){ 
	return (f->nItens == f->capacidade);
}

//Visualizando a fila:
void mostrarFila(struct Fila *f){
	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){
		printf("%.2f\t",f->dados[i++]);
		if (i == f->capacidade){
			i=0; }
	}
	printf("\n\n"); }

int main(){
	int opcao, capa;
	float valor;
	struct Fila umaFila;
  struct Fila copia;

	//Criando a fila:
	printf("\nDigite a capacidade da fila: ");
	scanf("%d",&capa);
	criarFila(&umaFila, capa);

	//Menu de opções:
	while( 1 ){
		printf("\nDigite:\n\n0 - Sair\n1 - Adicionar\n2 - Remover\n3 - Visualizar\n4 - Duplicar\n5 - Visualizar cópia\n\nOpção: ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: 
				if (estaCheia(&umaFila)){
					printf("\nFila Cheia!!!\n\n");
				}
				else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&umaFila,valor);
				}
				break;

			case 2: 
				if (estaVazia(&umaFila)){
					printf("\nFila vazia!!!\n\n");
				}
				else {
					valor = remover(&umaFila);
					printf("\n%1f removido com sucesso\n\n", valor) ; 
				}
				break;

				case 3:
					if (estaVazia(&umaFila)){
						printf("\nFila vazia!!!\n\n");
					}
					else {
						printf("\nFila => ");
						mostrarFila(&umaFila);
					}
					break;

        case 4:
          copia = umaFila;
          printf("Cópiado com sucesso!\n");
          break;

      case 5:
          if (estaVazia(&copia)){
						printf("\nFila vazia!!!\n\n");
					}
					else {
						printf("\nCópia da Fila => ");
						mostrarFila(&copia);
					}
					break;

				default:
					printf("\nOpção Inválida\n\n");
		}
	}
}