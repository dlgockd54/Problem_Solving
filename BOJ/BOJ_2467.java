import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] solutions = new int[n];
        int answerValueOne = 0;
        int answerValueTwo = 0;
        int answer = 2000000001;

        for (int i = 0; i < n; i++) {
            solutions[i] = sc.nextInt();
        }

        for (int i = 0; i < n - 1; i++) {
            int begin = i + 1;
            int end = n - 1;

            while (begin <= end) {
                int middle = (begin + end) / 2;
                int tempAnswer = solutions[i] + solutions[middle];
                int absTempAnswer = Math.abs(tempAnswer);
                int leftSum = 2000000001;
                int rightSum = 2000000001;

                if (absTempAnswer < Math.abs(answer)) {
                    answer = tempAnswer;
                    answerValueOne = solutions[i];
                    answerValueTwo = solutions[middle];
                }

                if (answer == 0) {
                    break;
                }

                if (middle - 1 > i) {
                    leftSum = solutions[i] + solutions[middle - 1];
                }

                if (middle + 1 < n) {
                    rightSum = solutions[i] + solutions[middle + 1];
                }

                if (Math.abs(leftSum) < absTempAnswer
                        && Math.abs(leftSum) < Math.abs(rightSum)) {
                    end = middle - 1;
                } else if (Math.abs(rightSum) < absTempAnswer
                        && Math.abs(leftSum) > Math.abs(rightSum)) {
                    begin = middle + 1;
                } else {
                    break;
                }
            }
        }

        System.out.println(answerValueOne + " " + answerValueTwo);
    }
}
