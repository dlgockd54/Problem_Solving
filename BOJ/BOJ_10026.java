import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    private static class Pair {

        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Pair> q = new LinkedList<>();
        int N = sc.nextInt();
        char[][] image = new char[N][N];
        boolean[][] hasVisited = new boolean[N][N];
        int answer = 0;
        int colorWeaknessAnswer = 0;

        for (int i = 0; i < N; i++) {
            Arrays.fill(hasVisited[i], false);
        }

        for (int i = 0; i < N; i++) {
            image[i] = sc.next().toCharArray();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!hasVisited[i][j]) {
                    answer++;

                    hasVisited[i][j] = true;

                    q.add(new Pair(i, j));

                    while (!q.isEmpty()) {
                        Pair first = q.element();
                        int[] dx = new int[]{0, 0, 1, -1};
                        int[] dy = new int[]{1, -1, 0, 0};

                        for (int k = 0; k < 4; k++) {
                            int newX = dx[k] + first.x;
                            int newY = dy[k] + first.y;

                            if (newX > -1 && newX < N && newY > -1 && newY < N) {
                                if (!hasVisited[newX][newY]
                                        && image[newX][newY] == image[first.x][first.y]) {
                                    hasVisited[newX][newY] = true;

                                    q.add(new Pair(newX, newY));
                                }
                            }
                        }

                        if (image[first.x][first.y] == 'R') {
                            image[first.x][first.y] = 'G';
                        }

                        q.remove();
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            Arrays.fill(hasVisited[i], false);
        }

        q.clear();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!hasVisited[i][j]) {
                    colorWeaknessAnswer++;

                    hasVisited[i][j] = true;

                    q.add(new Pair(i, j));

                    while (!q.isEmpty()) {
                        Pair first = q.element();
                        int[] dx = new int[]{0, 0, 1, -1};
                        int[] dy = new int[]{1, -1, 0, 0};

                        for (int k = 0; k < 4; k++) {
                            int newX = dx[k] + first.x;
                            int newY = dy[k] + first.y;

                            if (newX > -1 && newX < N && newY > -1 && newY < N) {
                                if (!hasVisited[newX][newY]
                                        && image[newX][newY] == image[first.x][first.y]) {
                                    hasVisited[newX][newY] = true;

                                    q.add(new Pair(newX, newY));
                                }
                            }
                        }

                        q.remove();
                    }
                }
            }
        }

        System.out.println(answer + " " + colorWeaknessAnswer);
    }
}
