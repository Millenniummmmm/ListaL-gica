import java.util.Scanner;
import java.util.Locale;

public class logica {

    public static int negacao(int a, int b) {
        int resultado = 0, resultado2 = 0;
        if (!(a == b))
            resultado++;
        if (!(a < 2))
            resultado2++;

        System.out.println("\n\tExemplo 1: ~(A = B).");
        System.out.print("\tEntão a expressão é:");
        if (resultado == 0)
            System.out.println(" Falsa (0).");
        else
            System.out.println(" Verdadeira (1).");

        System.out.println("\n\tExemplo 2: ~(A < 2).");
        System.out.print("\tEntão a expressão é:");
        if (resultado2 == 0)
            System.out.println(" Falsa (0).");
        else
            System.out.println(" Verdadeira (1).");

        return 0;
    }

    public static int disjuncao(int a, int b) {
        int resultado = 0, resultado2 = 0;

        if (!(a != 0 || b != 0)) {
            resultado++;
        }

        if (a != 0 || b != 0) {
            resultado2++;
        }

        System.out.println("\n\tExemplo 1: ~(A v B) = 0.");
        System.out.print("\tEntão a expressão é:");
        if (resultado == 0) {
            System.out.println(" Falsa (0).");
        } else {
            System.out.println(" Verdadeira (1).");
        }

        System.out.println("\n\tExemplo 2: (A v B) = 0.");
        System.out.print("\tEntão a expressão é:");
        if (resultado2 == 0) {
            System.out.println(" Falsa (0).");
        } else {
            System.out.println(" Verdadeira (1).");
        }

        return 0;
    }

    public static int conjuncao(int a, int b) {
        int resultado = 0, resultado2 = 0;
        if (!(a != 0 && b != 0))
            resultado++;
        if ((a != 0 && b != 0))
            resultado2++;

        System.out.println("\n\tExemplo 1: ~(A ^ B) = 1.");
        System.out.print("\tEntão a expressão é:");
        if (resultado == 0)
            System.out.println(" Falsa (0).");
        else
            System.out.println(" Verdadeira (1).");

        System.out.println("\n\tExemplo 2: (A ^ B) = 1.");
        System.out.print("\tEntão a expressão é:");
        if (resultado2 == 0)
            System.out.println(" Falsa (0).");
        else
            System.out.println(" Verdadeira (1).");

        return 0;
    }

    public static void main(String[] args) {
        Locale.setDefault(new Locale("pt", "BR"));
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n\t==============Trabalho de Lógica==============\n");
        System.out.println("\n\tPrimeira Questão:");
        System.out.println("\n\tDigite dois valores a e b, respectivamente.");
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        System.out.println("\n\tExemplos de Negação: ");
        negacao(a, b);

        System.out.println("\n\tExemplos de disjunção: ");
        disjuncao(a, b);

        System.out.println("\n\tExemplos de conjunção: ");
        conjuncao(a, b);

        scanner.nextLine();
        System.out.println("Digite uma sentença:");
        String sentenca = scanner.nextLine();
        System.out.println(sentenca);

        scanner.close();
    }
}
