import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {

    public int[] topKFrequent(int[] nums, int k) {
        int[] answer = new int[k];
        HashMap<Integer, Integer> map = new HashMap<>();
        PriorityQueue<Map.Entry<Integer, Integer>> pq =
                new PriorityQueue<Map.Entry<Integer, Integer>>(createComparator());

        for (int num : nums) {
            int count = map.getOrDefault(num, 0) + 1;

            map.put(num, count);
        }

        pq.addAll(map.entrySet());

        for (int i = 0; i < k; i++) {
            answer[i] = pq.remove().getKey();
        }

        return answer;
    }

    private Comparator<Map.Entry<Integer, Integer>> createComparator() {
        return (o1, o2) -> {
            if (o1.getValue() > o2.getValue()) {
                return -1;
            } else if (o1.equals(o2)) {
                return 0;
            }

            return 1;
        };
    }
}

public class Main {

    public static void main(String[] args) {
        for (int num : new Solution().topKFrequent(new int[]{2, 2, 3, 1, 1, 1}, 2)) {
            System.out.println(num);
        }
    }
}