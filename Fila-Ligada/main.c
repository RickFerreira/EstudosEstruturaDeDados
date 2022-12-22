#include <stdio.h>


/*registro que reprensentará cada elemento da pilha*/

typedef struct Elemento{
	int num;
	struct Elemento *prox;
} Elemento;


typedef struct Fila{
    struct Elemento *inicio; 
    struct Elemento *fim; 
    int num_elementos;
} Fila;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->num_elementos=0;
    }
    return fi;
}

void enqueue(Fila *fi, int inf){
	Elemento *novoNo =(Elemento*) malloc(sizeof(Elemento));
	novoNo->num =inf;
	novoNo->prox = NULL;
	if(fi->inicio == NULL){
		fi->inicio = novoNo;
		fi->fim = novoNo;
    fi->num_elementos++;
	}else{
		fi->fim->prox = novoNo;
		fi->fim = novoNo;
    fi->num_elementos++;
	}
}		

void enqueue2(Fila *fi, int inf){
	Elemento *novoNo =(Elemento*) malloc(sizeof(Elemento));
	novoNo->num =inf;
	novoNo->prox = NULL;
	if(fi->inicio == NULL){
		fi->inicio = novoNo;
		fi->fim = novoNo;
    fi->num_elementos++;
	}else{
		Elemento *aux=fi->inicio;

    while(aux->prox!=NULL){
      aux=aux->prox;
    }
    aux->prox=novoNo;
		fi->fim = novoNo;
    fi->num_elementos++;
	}
}	

void imprimir(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
    Elemento *aux = fi->inicio;
    printf("Início - ");
		while(aux != NULL){
			printf(" %d - ", aux->num);
			aux = aux->prox;
		}
    printf(" - Fim");
	}
}	

/*o elemento a ser removido será sempre o primeiro elemento inserido(inicio)*/
int dequeue(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
    return -1;
	}else{
		Elemento *aux = fi->inicio;
    int r=aux->num;
		fi->inicio = fi->inicio->prox;
    fi->num_elementos--;
		free(aux);
    return r;
	}
}		


/*a fila será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		Elemento *aux = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(aux);
			aux = fi->inicio;
		}while(aux != NULL);
		printf("\nFila Esvaziada!!");
	}
}	

int main(void) {
  Fila *fi = cria_fila();
  enqueue(fi,10);
  enqueue(fi,5);
  enqueue(fi,8);
  enqueue(fi,20);
  enqueue(fi,51);
  enqueue(fi,11);
  enqueue2(fi,100);
  imprimir(fi);
  printf("\nNum_Elementos: %d", fi->num_elementos);
  printf("\n\n");
  dequeue(fi);
  dequeue(fi);
  dequeue(fi);
  imprimir(fi);
  printf("\nNum_Elementos: %d\n", fi->num_elementos);

  return 0;
}

