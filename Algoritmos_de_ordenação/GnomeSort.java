public class GnomeSort {

    //Funciona como se fosse o bubbleSort, ele vai indo indice a indice e comparando de par em par quem é menor;
    //Quando o indice atual é menor do que o anterior ele troca de posição;
    //Mas diferente do bubble, ele volta uma casa quando acha um indice menor para ver se ele também é menor que outros anteriores;
    public static void gnomeSort(int[] vetor) {
        //Guardando o tamanho da lista
        int tamanho = vetor.length;
        //Iniciando o indice já do segundo valor
        int i = 1;
        //Enquanto não chegar no último valor ele continua
        while (i < tamanho){
            //Se tiver no primeiro valor ou o indice atual for MAIOR que o atenrior passa pra o proximo
            if (i == 0 || (vetor[i] >= vetor[i - 1])) {
                i++;
            //Casos o indice atual seja MENOR ele troca de lugar com o anterior e volta uma casa
            } else {
                int guardar = vetor[i];
                vetor[i] = vetor[i - 1];
                vetor[i - 1] = guardar;
                i--;
            }
            //Enquanto o indice atual for menor ele volta uma casa até que chegue no indice 0, onde volta ir pra frente
        }
    }

    public static void main(String[] args) {
        int[] vetor = {4, 5, 9, 2, 3, 7, 6, 8, 1, -1, -10, 0};
        int[] copiaVetor = new int[vetor.length];

        System.out.println("Lista original: ");
        for (int i : vetor) {
            System.out.print(i + " ");
        }

        System.out.println("\n");

        System.out.println("Gnome Sort: ");
        copiaVetor = vetor.clone();
        gnomeSort(copiaVetor);
        for (int i : copiaVetor) {
            System.out.print(i + " ");
        }
    }
}
