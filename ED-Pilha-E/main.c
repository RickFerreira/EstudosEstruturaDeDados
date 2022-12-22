#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    char site[30];
    struct no *prox;
};

typedef struct no No;

typedef struct pilha {
    int cont;
    No *topo;
} Pilha;


Pilha* create () {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->cont=0;
    return p;
}

int isEmpty (Pilha *p) {
    if(p->cont == 0){
      return 1;
    }
    else{
      return 0;
    }
}

int isAdd(Pilha *p, char *elemento){
  No *aux=p->topo;

  while(aux!=NULL){
    if(strcmp(aux->site,elemento)==0){
      return 0;
    }
    aux=aux->prox;
  }
  return 1;
}

// Push
void push (Pilha *p, char *elemento) {
  if(isAdd(p,elemento)){
    No *NovoNo = (No*)malloc(sizeof(No));
    strcpy(NovoNo->site, elemento);

    if (!isEmpty(p)) {
        NovoNo->prox = p->topo;
    } 

    p->topo = NovoNo;
    p->cont++;
  }
  else{
    printf("Elemento repetido!");
  }
}

// Pop

void pop (Pilha *p) {
    if (!isEmpty(p)) {
        No *NoDel = p->topo;
        p->topo = NoDel->prox;
        //p->topo = p->topo->prox;
        p->cont--;
        free(NoDel);
        printf("Nó removido!");
    } else {
        printf("Pilha já está vazia.\n");
    }
}

// Peek

char* peek (Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia. Não há elementos no topo\n");
        return "-1";
    } else {
        return p->topo->site;
    }
}

void imprimir(Pilha *p){
  No *aux=p->topo;
	if(aux == NULL) 
    printf("A Pilha se encontra vazia!\n"); 
	else{
    printf("(topo) -> ");
		while(aux != NULL){
      printf("%s -> ", aux->site);
			aux = aux->prox;
		}
	}
}

void libera(Pilha* p){
	No* q = p->topo;
	while(q != NULL){
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

int main () {
  Pilha* x= create();;
	
  int opt;
  char texto[30];
  do{
    printf("Digite:\n1-push\n2-pop\n3-print\n4-sair\n");
    scanf("%d", &opt);

    switch(opt){
      case 1:
        printf("Digite um site: ");
        scanf("%s", texto);
        push(x, texto);
        printf("Site adicionado com sucesso!\n");
      break;
      case 2:
        pop(x);
        break;
      case 3:
        imprimir(x);
        break;
      case 4:
        libera(x);
        opt=-1;
        break;
      default:
        printf("Opção inválida! Tente de novo!\n");
        opt=0;
    }
  }while(opt!=-1);


  return 0;
}

