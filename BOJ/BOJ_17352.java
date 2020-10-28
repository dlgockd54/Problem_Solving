import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numOfIsland = sc.nextInt();
        int[] parentIslands = new int[numOfIsland + 1];

        for (int i = 0; i <= numOfIsland; i++) {
            parentIslands[i] = i;
        }

        for (int i = 0; i < numOfIsland - 2; i++) {
            int firstIsland = sc.nextInt();
            int secondIsland = sc.nextInt();

            union(parentIslands, firstIsland, secondIsland);
        }

        for (int i = 2; i <= numOfIsland; i++) {
            if (parentIslands[1] != find(parentIslands, i)) {
                System.out.println(parentIslands[1] + " " + parentIslands[i]);

                break;
            }
        }
    }

    private static void union(int[] parentIslands, int islandFirst, int islandSecond) {
        int parentOfFirst = find(parentIslands, islandFirst);
        int parentOfSecond = find(parentIslands, islandSecond);

        if (parentOfFirst < parentOfSecond) {
            parentIslands[parentOfSecond] = parentOfFirst;
            parentIslands[islandSecond] = parentOfFirst;
        } else {
            parentIslands[parentOfFirst] = parentOfSecond;
            parentIslands[islandFirst] = parentOfSecond;
        }
    }

    private static int find(int[] parentIslands, int island) {
        if (parentIslands[island] == island) {
            return island;
        }

        parentIslands[island] = find(parentIslands, parentIslands[island]);

        return parentIslands[island];
    }
}
