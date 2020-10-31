import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numOfSet = sc.nextInt();
        int numOfOperation = sc.nextInt();
        int[] setParents = new int[numOfSet + 1];

        for (int i = 1; i <= numOfSet; i++) {
            setParents[i] = i;
        }

        for (int i = 0; i < numOfOperation; i++) {
            int operation = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();

            if (operation == 0) {
                union(setParents, a, b);
            } else {
                if (find(setParents, a) == find(setParents, b)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }

    private static void union(int[] setParents, int a, int b) {
        int parentElementOfA = find(setParents, a);
        int parentElementOfB = find(setParents, b);

        if (parentElementOfA < parentElementOfB) {
            setParents[parentElementOfB] = parentElementOfA;
        } else {
            setParents[parentElementOfA] = parentElementOfB;
        }
    }

    private static int find(int[] setParents, int targetElement) {
        if (setParents[targetElement] == targetElement) {
            return targetElement;
        }

        setParents[targetElement] = find(setParents, setParents[targetElement]);

        return setParents[targetElement];
    }
}
