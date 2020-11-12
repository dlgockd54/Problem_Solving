import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    private static class Pair {

        int x;
        int y;
        int cnt;

        public Pair(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int row = sc.nextInt();
        int col = sc.nextInt();
        char[][] map = new char[row][col];
        boolean[][] hasVisited = new boolean[row][col];
        Queue<Pair> q = new LinkedList<Pair>();
        int[] dx = new int[]{0, 0, 1, -1};
        int[] dy = new int[]{1, -1, 0, 0};
        int answer = 0;

        for (int i = 0; i < row; i++) {
            map[i] = sc.next().toCharArray();
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j] == 'L') {
                    for (int k = 0; k < row; k++) {
                        Arrays.fill(hasVisited[k], false);
                    }

                    hasVisited[i][j] = true;

                    q.add(new Pair(i, j, 0));

                    while (!q.isEmpty()) {
                        Pair current = q.element();

                        if (answer < current.cnt) {
                            answer = current.cnt;
                        }

                        for (int k = 0; k < 4; k++) {
                            int newX = dx[k] + current.x;
                            int newY = dy[k] + current.y;

                            if (newX > -1 && newX < row && newY > -1 && newY < col) {
                                if (!hasVisited[newX][newY] && map[newX][newY] == 'L') {
                                    hasVisited[newX][newY] = true;

                                    q.add(new Pair(newX, newY, current.cnt + 1));
                                }
                            }
                        }

                        q.remove();
                    }
                }
            }
        }

        System.out.println(answer);
    }
}
