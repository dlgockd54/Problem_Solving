import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numOfCountry = sc.nextInt();
        int numOfRecord = sc.nextInt();
        int[] parentCountries = new int[numOfCountry + 1];
        int[] powerOfCountries = new int[numOfCountry + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 1; i <= numOfCountry; i++) {
            parentCountries[i] = i;
            powerOfCountries[i] = sc.nextInt();
        }

        for (int i = 0; i < numOfRecord; i++) {
            int unionOrWar = sc.nextInt();
            int countryOne = sc.nextInt();
            int countryTwo = sc.nextInt();

            if (unionOrWar == 1) {
                union(parentCountries, powerOfCountries, countryOne, countryTwo);
            } else if (unionOrWar == 2) {
                war(parentCountries, powerOfCountries, countryOne, countryTwo);
            }
        }

        for (int power : powerOfCountries) {
            if (power > 0) {
                pq.add(power);
            }
        }

        System.out.println(pq.size());

        while (!pq.isEmpty()) {
            System.out.print(pq.element() + " ");
            pq.remove();
        }
    }

    private static void union(
            int[] parents, int[] powerOfCountries, int countryOne, int countryTwo) {
        int parentOfCountryOne = find(parents, countryOne);
        int parentOfCountryTwo = find(parents, countryTwo);

        if (powerOfCountries[parentOfCountryOne] < powerOfCountries[parentOfCountryTwo]) {
            powerOfCountries[parentOfCountryTwo] += powerOfCountries[parentOfCountryOne];
            powerOfCountries[parentOfCountryOne] = 0;
            parents[parentOfCountryOne] = parents[parentOfCountryTwo];
        } else {
            powerOfCountries[parentOfCountryOne] += powerOfCountries[parentOfCountryTwo];
            powerOfCountries[parentOfCountryTwo] = 0;
            parents[parentOfCountryTwo] = parents[parentOfCountryOne];
        }
    }

    private static int find(int[] parents, int targetCountry) {
        if (parents[targetCountry] == targetCountry) {
            return targetCountry;
        }

        parents[targetCountry] = find(parents, parents[targetCountry]);

        return parents[targetCountry];
    }

    private static void war(
            int[] parents, int[] powerOfCountries, int countryOne, int countryTwo) {
        int parentOfCountryOne = find(parents, countryOne);
        int parentOfCountryTwo = find(parents, countryTwo);

        if (powerOfCountries[parentOfCountryOne] < powerOfCountries[parentOfCountryTwo]) {
            powerOfCountries[parentOfCountryOne] *= -1;
        } else {
            powerOfCountries[parentOfCountryTwo] *= -1;
        }

        union(parents, powerOfCountries, parentOfCountryOne, parentOfCountryTwo);
    }
}
