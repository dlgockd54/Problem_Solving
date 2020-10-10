import java.util.Scanner;
import java.util.Stack;

class Solution {

    public String solution(int[] sequence) {
        StringBuilder answer = new StringBuilder();
        Stack<Integer> stk = new Stack<>();
        int biggestNum = 0;

        for (int num : sequence) {
            if (num > biggestNum) {
                for (int i = biggestNum + 1; i <= num; i++) {
                    stk.push(i);
                    answer.append("+\n");
                    biggestNum = biggestNum < i ? i : biggestNum;
                }

                stk.pop();
                answer.append("-\n");
            } else {
                if (!stk.isEmpty()) {
                    while (!stk.isEmpty()) {
                        int top = stk.peek();

                        if (top == num) {
                            stk.pop();
                            answer.append("-\n");

                            break;
                        } else {
                            return "NO";
                        }
                    }
                } else {
                    return "NO";
                }
            }
        }

        if (!stk.isEmpty()) {
            return "NO";
        }

        return answer.toString();
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] sequence = new int[n];

        for (int i = 0; i < n; i++) {
            sequence[i] = sc.nextInt();
        }

        System.out.println(new Solution().solution(sequence));
    }
}