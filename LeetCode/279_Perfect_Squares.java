import java.util.LinkedList;
import java.util.Queue;

class Solution {

    private static class Pair {

        int first;
        int second;

        public Pair(int f, int s) {
            first = f;
            second = s;
        }
    }

    public int numSquares(int n) {
        Queue<Pair> q = new LinkedList<>();
        boolean[] isVisited = new boolean[n + 1];
        int answer = Integer.MAX_VALUE;

        if (n == 1) {
            answer = 1;
        } else if (n > 1) {
            for (int i = 1; i * i <= n; i++) {
                isVisited[i * i] = true;

                q.add(new Pair(i * i, 1));
            }

            while (!q.isEmpty()) {
                Pair element = q.element();
                int value = element.first;
                int count = element.second;

                if (value == n) {
                    answer = answer > count ? count : answer;
                }

                for (int i = 1; i * i + value <= n; i++) {
                    int next = i * i + value;

                    if (!isVisited[next]) {
                        isVisited[next] = true;

                        q.add(new Pair(next, count + 1));
                    }
                }

                q.remove();
            }
        }

        return answer;
    }
}

public class Main {

    public static void main(String[] args) {
        System.out.println(new Solution().numSquares(12));
        System.out.println(new Solution().numSquares(1));
        System.out.println(new Solution().numSquares(4));
    }
}