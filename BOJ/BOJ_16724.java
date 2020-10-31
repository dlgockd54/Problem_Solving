import java.util.HashSet;
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
        int row = sc.nextInt();
        int col = sc.nextInt();
        int answer = 0;
        char[][] map = new char[row][col];
        Pair[][] roots = new Pair[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                roots[i][j] = new Pair(i, j);
            }
        }

        for (int i = 0; i < row; i++) {
            map[i] = sc.next().toCharArray();
        }

        answer = bfs(map, roots);

        System.out.println(answer);
    }

    private static int bfs(char[][] map, Pair[][] roots) {
        int row = map.length;
        int col = map[0].length;
        int answer = 0;
        boolean[][] hasVisited = new boolean[row][col];
        Queue<Pair> q = new LinkedList<>();
        boolean[][] isCountRoot = new boolean[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!hasVisited[i][j]) {
                    hasVisited[i][j] = true;

                    q.add(new Pair(i, j));

                    while (!q.isEmpty()) {
                        Pair element = q.element();
                        int x = element.x;
                        int y = element.y;
                        int[] dx = new int[]{0, 1, 0, -1};
                        int[] dy = new int[]{1, 0, -1, 0};
                        int newX = x;
                        int newY = y;

                        switch (map[x][y]) {
                            case 'R':
                                newX += dx[0];
                                newY += dy[0];

                                break;
                            case 'D':
                                newX += dx[1];
                                newY += dy[1];

                                break;
                            case 'L':
                                newX += dx[2];
                                newY += dy[2];

                                break;
                            case 'U':
                                newX += dx[3];
                                newY += dy[3];
                        }

                        Pair newPair = new Pair(newX, newY);

                        union(roots, element, newPair);

                        if (!hasVisited[newX][newY]) {
                            hasVisited[newX][newY] = true;
                            q.add(newPair);
                        }

                        q.remove();
                    }
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                Pair root = find(roots, new Pair(i, j));
                int x = root.x;
                int y = root.y;

                if (!isCountRoot[x][y]) {
                    isCountRoot[x][y] = true;
                    answer++;
                }
            }
        }

        return answer;
    }

    private static void union(Pair[][] roots, Pair a, Pair b) {
        Pair rootOfA = find(roots, a);
        Pair rootOfB = find(roots, b);

        if (rootOfA.x < rootOfB.x || rootOfA.y < rootOfB.y) {
            roots[rootOfB.x][rootOfB.y] = rootOfA;
        } else {
            roots[rootOfA.x][rootOfA.y] = rootOfB;
        }
    }

    private static Pair find(Pair[][] roots, Pair targetPair) {
        Pair rootPair = roots[targetPair.x][targetPair.y];

        if (rootPair.x == targetPair.x && rootPair.y == targetPair.y) {
            return targetPair;
        }

        roots[targetPair.x][targetPair.y] = find(roots, roots[targetPair.x][targetPair.y]);

        return roots[targetPair.x][targetPair.y];
    }
}
