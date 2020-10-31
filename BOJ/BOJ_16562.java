import java.util.HashSet;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numOfFriend = sc.nextInt();
        int numOfRelation = sc.nextInt();
        int amountOfMoney = sc.nextInt();
        int[] rootFriends = new int[numOfFriend + 1];
        int[] costs = new int[numOfFriend + 1];
        HashSet<Integer> friendSet = new HashSet<>();
        int totalCosts = 0;

        for (int i = 0; i <= numOfFriend; i++) {
            rootFriends[i] = i;
        }

        for (int i = 1; i <= numOfFriend; i++) {
            costs[i] = sc.nextInt();
        }

        for (int i = 0; i < numOfRelation; i++) {
            int friendA = sc.nextInt();
            int friendB = sc.nextInt();

            union(rootFriends, costs, friendA, friendB);
        }

        for (int i = 1; i <= numOfFriend; i++) {
            int root = find(rootFriends, i);
            int cost = costs[root];

            if (!friendSet.contains(root)) {
                totalCosts += cost;

                friendSet.add(root);
            }

            if (totalCosts > amountOfMoney) {
                break;
            }
        }

        if (totalCosts <= amountOfMoney) {
            System.out.println(totalCosts);
        } else {
            System.out.println("Oh no");
        }
    }

    private static void union(int[] rootFriends, int[] costs, int friendA, int friendB) {
        int rootOfFriendA = find(rootFriends, friendA);
        int rootOfFriendB = find(rootFriends, friendB);

        if (costs[rootOfFriendA] < costs[rootOfFriendB]) {
            rootFriends[rootOfFriendB] = rootOfFriendA;
        } else {
            rootFriends[rootOfFriendA] = rootOfFriendB;
        }
    }

    private static int find(int[] rootFriends, int targetFriend) {
        if (rootFriends[targetFriend] == targetFriend) {
            return targetFriend;
        }

        rootFriends[targetFriend] = find(rootFriends, rootFriends[targetFriend]);

        return rootFriends[targetFriend];
    }
}
