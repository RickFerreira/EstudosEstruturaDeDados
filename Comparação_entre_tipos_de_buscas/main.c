#include <stdio.h>
#include <string.h>
#include<time.h>
#include <stdlib.h>
#define TAM 1000

//usado para ordenar os dados, para depois, poder usar a busca binária.
void bubble_sort (int vetor[], int n) {
    int fim, j, aux;
    for (fim = n - 1; fim > 0; fim--) {
        for (j = 0; j < fim; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int buscaLinear(int *vet, int tam, int rg){
  for(int i=0; i<tam; i++) {
    if(vet[i]==rg) 
        return i;
    }
  return -1; 
}

int buscaBinaria(int *vet, int tam, int rg){
  int fim=tam-1,meio,inicio=0;
  while(inicio<=fim) {
    meio=(inicio+fim)/2;
    if(vet[meio]==rg) 
        return meio;
    else if (vet[meio]> rg)
      fim=meio-1;
    else
      inicio=meio+1;
    }
  return -1; 
}

//Comparando a busca linear com a binária.
int main(void) {
  int vetor[TAM];

  for(int i=0;i<TAM;i++){
    vetor[i]=rand() % 10000;
  }

  //pegando o tempo da busca linear
  clock_t begin = clock();
  
  int x=buscaLinear(vetor, TAM, 10);
  if(x!=-1){
    printf("\n O nome do funcionário é: %d ", vetor[x]);  
  }
  else
    printf("Rg não encontrado!");

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("\n Tempo: %lf \n", time_spent);


  //Nova busca!


  bubble_sort(vetor,TAM);//Ordenando!

  //pegando o tempo da busca binária
  begin = clock();

  x=buscaBinaria(vetor, TAM, 10);
  if(x!=-1){
    printf("\n O nome do funcionário é: %d ", vetor[x]);  
  }
  else
    printf("Rg não encontrado!\n");
  
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo: %lf \n", time_spent);

  return 0;
}



