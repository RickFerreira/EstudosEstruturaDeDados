import java.util.Scanner;

public class ValoresPares {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número: ");
        int N = scanner.nextInt();
        imprimirParesRecursivo(N);
    }

    public static void imprimirParesRecursivo(int n) {
        if (n > 0) {
            imprimirParesRecursivo(n - 1);
            if (n % 2 == 0) {
                System.out.print(n + " ");
            }

        }
    }
}