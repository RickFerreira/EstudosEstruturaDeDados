public class AlgoritmosDeOrdenacaoInterativos {

    //Vai percorrer a lista indice por indice e colocando o menor valor em cada
    static void selectionSort(int[] vetor) {
        int Tamanho = vetor.length;
        int minimo, auxiliar;
        for (int i = 0; i < (Tamanho - 1); i++) {
            minimo = i; //O minimo é o primeiro número não ordenado ainda
            for (int j = i + 1; j < Tamanho; j++) {
                if (vetor[j] < vetor[minimo]) {
                    minimo = j; //Caso tenha algum numero menor ele faz a troca do minimo
                }
            }
            if (i != minimo) {
                auxiliar = vetor[i];
                vetor[i] = vetor[minimo];
                vetor[minimo] = auxiliar;
            }
        }
    }

    static void bubbleSort(int[] vetor) {
        int n = vetor.length;
        int temp = 0, tempC = 0;
        for (int fim = n - 1; fim > 0; fim--) {
            for (int j = 0; j < fim; j++) {
                tempC++;
                if (vetor[j] > vetor[j + 1]) {
                    temp++;
                    int auxiliar = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = auxiliar;
                }
            }
        }
    }

    static void insertionSort(int[] v) {
        int n = v.length;
        for (int i = 1; i < n; i++) {
            int auxiliar = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > auxiliar) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = auxiliar;
        }
    }

    public static void main(String[] args) {
        int[] vetor = {5, 4, 1, 3, 2, 7, 6, 8, 9};
        int[] copiaVetor = new int[vetor.length];

        System.out.println("Lista original: ");
        for (int i : vetor) {
            System.out.print(i + " ");
        }

        System.out.println("\n");

        System.out.println("Selection Sort: ");
        copiaVetor = vetor.clone();
        selectionSort(copiaVetor);
        for (int i : copiaVetor) {
            System.out.print(i + " ");
        }

        System.out.println("\n");

        System.out.println("Bubble Sort: ");
        copiaVetor = vetor.clone();
        bubbleSort(copiaVetor);
        for (int i : copiaVetor) {
            System.out.print(i + " ");
        }

        System.out.println("\n");

        System.out.println("Insertion Sort: ");
        copiaVetor = vetor.clone();
        insertionSort(copiaVetor);
        for (int i : copiaVetor) {
            System.out.print(i + " ");
        }
    }
}
