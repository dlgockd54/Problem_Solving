import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numOfCity = sc.nextInt();
        int numOfVisit = sc.nextInt();
        int[] rootCities = new int[numOfCity + 1];
        int[] visitPlan = new int[numOfVisit];
        boolean isPossible = true;

        for (int i = 1; i <= numOfCity; i++) {
            rootCities[i] = i;
        }

        for (int i = 1; i <= numOfCity; i++) {
            for (int j = 1; j <= numOfCity; j++) {
                int isConnected = sc.nextInt();

                if (j >= i && isConnected == 1) {
                    union(rootCities, i, j);
                }
            }
        }

        for (int i = 0; i < numOfVisit; i++) {
            visitPlan[i] = sc.nextInt();
        }

        for (int i = 1; i < numOfVisit; i++) {
            if (find(rootCities, visitPlan[i - 1]) != find(rootCities, visitPlan[i])) {
                isPossible = false;

                break;
            }
        }

        if (isPossible) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static void union(int[] rootCities, int cityA, int cityB) {
        int rootOfCityA = find(rootCities, cityA);
        int rootOfCityB = find(rootCities, cityB);

        if (rootOfCityA < rootOfCityB) {
            rootCities[rootOfCityB] = rootOfCityA;
        } else {
            rootCities[rootOfCityA] = rootOfCityB;
        }
    }

    private static int find(int[] rootCities, int targetCity) {
        if (rootCities[targetCity] == targetCity) {
            return targetCity;
        }

        rootCities[targetCity] = find(rootCities, rootCities[targetCity]);

        return rootCities[targetCity];
    }
}
