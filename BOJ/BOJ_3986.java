import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

class Solution {

    public void solution(ArrayList<String> words) {
        int answer = 0;

        for (String word : words) {
            if (isGoodWord(word)) {
                answer++;
            }
        }

        System.out.println(answer);
    }

    private boolean isGoodWord(String word) {
        Stack<Character> stk = new Stack<>();
        boolean isGoodWord = false;
        int length = word.length();

        for (int i = 0; i < length; i++) {
            char c = word.charAt(i);

            if (stk.isEmpty()) {
                stk.push(c);
            } else {
                char top = stk.peek();

                if (top == c) {
                    stk.pop();
                } else {
                    stk.push(c);
                }
            }
        }

        isGoodWord = stk.isEmpty();

        return isGoodWord;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> words = new ArrayList<>();
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            words.add(sc.next());
        }

        new Solution().solution(words);
    }
}