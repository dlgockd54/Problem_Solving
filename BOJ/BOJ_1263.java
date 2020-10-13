import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        PriorityQueue<Task> pq = new PriorityQueue<>(createComparator());
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int availableStartTime = -1;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            pq.add(new Task(sc.nextInt(), sc.nextInt()));
        }

        availableStartTime = pq.element().s - pq.element().t;
        pq.remove();

        while (!pq.isEmpty()) {
            Task task = pq.element();

            if (availableStartTime > task.s) {
                availableStartTime = task.s - task.t;
            } else {
                availableStartTime = availableStartTime - task.t;
            }

            pq.remove();
        }

        if (availableStartTime < 0) {
            answer = -1;
        } else {
            answer = availableStartTime;
        }

        System.out.println(answer);
    }

    private static Comparator<Task> createComparator() {
        return (o1, o2) -> {
            if (o1.s > o2.s) {
                return -1;
            } else if (o1.s == o2.s) {
                return 0;
            }

            return 1;
        };
    }

    private static class Task {

        int t;
        int s;

        public Task(int t, int s) {
            this.t = t;
            this.s = s;
        }
    }
}
