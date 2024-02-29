import java.util.Scanner;

public class Tabuada {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número para calcular a tabuada até 10: ");
        int numero = scanner.nextInt();
        int i = 1;
        multiplicar(numero, i);
    }
    public static void multiplicar(int numero, int i) {
        if (i <= 10){
            int resultado = numero * i;
            System.out.println(numero + " x " + i + " = " + resultado);
            i ++;
            multiplicar(numero, i);
        }
    }
}