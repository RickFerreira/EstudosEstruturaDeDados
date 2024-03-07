public class QuickSort {
    public static void quickSort(int[] array, int inicio, int fim) {
        if (inicio < fim) {
            int indicePivo = partition(array, inicio, fim);
            quickSort(array, inicio, indicePivo - 1);
            quickSort(array, indicePivo + 1, fim);
        }
    }
    public static int partition(int[] array, int inicio, int fim) {
        int pivo = array[inicio];
        int indiceMaiorElemento = fim + 1;

        for (int indiceAtual  = fim; indiceAtual  > inicio; indiceAtual --) {
            if (array[indiceAtual ] >= pivo) {
                indiceMaiorElemento--;
                int temp = array[indiceMaiorElemento];
                array[indiceMaiorElemento] = array[indiceAtual ];
                array[indiceAtual ] = temp;
            }
        }
        int temp = array[indiceMaiorElemento - 1];
        array[indiceMaiorElemento - 1] = array[inicio];
        array[inicio] = temp;
        return indiceMaiorElemento - 1;
    }

    public static void main(String[] args) {
        int[] array = {4, 5, 9, 2, 3, 7, 6, 8, 1, -1, -10, 0};

        System.out.println("Lista original: ");
        for (int i : array) {
            System.out.print(i + " ");
        }

        quickSort(array, 0, array.length - 1);

        System.out.println("\n\nQuick Sort: ");
        for (int i : array) {
            System.out.print(i + " ");
        }
    }
}
