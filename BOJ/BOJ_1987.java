import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        String[] board = new String[r];

        for (int i = 0; i < r; i++) {
            board[i] = sc.next();
        }

        System.out.println(recursion(board, "", 0, 0));
    }

    private static int recursion(String[] board, String str, int x, int y) {
        int result = str.length();

        if (!str.contains(String.valueOf(board[x].charAt(y)))) {
            String newStr = str + board[x].charAt(y);
            int[] dx = {0, 1, 0, -1};
            int[] dy = {1, 0, -1, 0};

            for (int i = 0; i < 4; i++) {
                int newX = dx[i] + x;
                int newY = dy[i] + y;

                if (newX > -1 && newX < board.length && newY > -1 && newY < board[0].length()) {
                    int ret = recursion(board, newStr, newX, newY);

                    result = result > ret ? result : ret;
                }
            }
        }

        return result;
    }
}
