#include <stdio.h>
#include <string.h>
#include<time.h>
#include <stdlib.h>


void selection_sort (int vetor[],int Tam) {
  int min, aux;
  for (int i = 0; i < (Tam - 1); i++) {
    min = i; /* O minimo é o primeiro número não ordenado ainda */
    for (int j = i+1; j < Tam; j++) {
      if (vetor[j] < vetor[min]) { /* Caso tenha algum numero menor ele faz a troca do minimo*/
        min = j;
      }
    }
    /* Se o minimo for diferente do primeiro número não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
    }
  }  
}

void bubble_sort (int vetor[], int n) {
    int fim, j, aux, temp=0, tempC=0;
    for (fim = n - 1; fim > 0; fim--) {
        for (j = 0; j < fim; j++) {
            tempC++;
            if (vetor[j] > vetor[j + 1]) {
                temp++;
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    printf("N de trocas: %d\nN de comparações: %d\n", temp, tempC);
}

void insertionSort(int v [], int n) { 
    int i, j, aux; 
    for(i = 1; i < n; i++) { 
      aux = v[i]; 
      j = i - 1; 
      while(j >= 0 && v[j] > aux) { 
        v[j+1] = v[j]; 
        j--; 
      } 
      v[j+1] = aux; 
    } 
}



void imprimir (int vetor[],int Tam) {
  /* Imprime o vetor ordenado */
  for (int i = 0; i < Tam; i++) {
    printf ("%d ",vetor[i]);
  }
  printf ("\n");
}

void copiar(int vet[], int vet2[], int Tam){
  for (int i = 0; i < Tam; i++) {
    vet2[i]=vet[i];
  }
}


int main(void) {


  int vetor[]={5, 4, 1, 3, 2};
  
  bubble_sort(vetor, 5);


  return 0;
}