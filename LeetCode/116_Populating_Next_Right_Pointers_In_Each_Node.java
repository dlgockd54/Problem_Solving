import java.util.LinkedList;
import java.util.Queue;

class Node {

    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}

class Solution {

    private static class Pair {

        Node first;
        int second;

        public Pair(Node first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public Node connect(Node root) {
        if (root != null) {
            Queue<Pair> q = new LinkedList<>();

            q.add(new Pair(root, 0));

            while (!q.isEmpty()) {
                Pair first = q.element();
                Node node = first.first;
                int level = first.second;

                if (node.left != null) {
                    q.add(new Pair(node.left, level + 1));
                }
                if (node.right != null) {
                    q.add(new Pair(node.right, level + 1));
                }

                q.remove();

                if (!q.isEmpty() && q.element().second == level) {
                    node.next = q.element().first;
                }
            }
        }

        return root;
    }
}

public class Main {

    public static void main(String[] args) {
        Node A = new Node(1);
        Node B = new Node(2);
        Node C = new Node(3);
        Node D = new Node(4);
        Node E = new Node(5);
        Node F = new Node(6);
        Node G = new Node(7);

        A.left = B;
        A.right = C;

        B.left = D;
        B.right = E;

        C.left = F;
        C.right = G;

        Node node = new Solution().connect(A);

        System.out.println(node.val);
    }
}