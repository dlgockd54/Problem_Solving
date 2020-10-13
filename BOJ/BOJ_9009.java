import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> fibonaccis = new ArrayList<>();
        ArrayList<ArrayList<Integer>> answer = new ArrayList<>();
        int idx = 2;
        int size = 0;
        int T = -1;

        fibonaccis.add(0);
        fibonaccis.add(1);

        while (true) {
            int num1 = fibonaccis.get(idx - 2);
            int num2 = fibonaccis.get(idx - 1);
            int sum = num1 + num2;

            if (sum <= 1000000000) {
                fibonaccis.add(sum);
                idx++;
            } else {
                break;
            }
        }

        T = sc.nextInt();
        size = fibonaccis.size();

        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();

            answer.add(new ArrayList<>());

            for (int j = size - 1; j > -1 && n > 0; j--) {
                int fibonacci = fibonaccis.get(j);

                if (fibonacci <= n) {
                    answer.get(i).add(fibonacci);
                    n -= fibonacci;
                }
            }
        }

        for (ArrayList<Integer> eachAnswer : answer) {
            int answerSize = eachAnswer.size();

            for (int i = answerSize - 1; i > -1; i--) {
                System.out.print(eachAnswer.get(i) + " ");
            }

            System.out.println();
        }
    }
}
