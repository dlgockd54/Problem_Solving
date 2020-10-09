import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode answer = null;
        ArrayList<TreeNode> pList = getDfsList(root, p);
        ArrayList<TreeNode> qList = getDfsList(root, q);
        int pSize = pList.size();
        int qSize = qList.size();
        int pIndex = pSize - 1;
        int qIndex = qSize - 1;

        for (; pIndex > -1 && qIndex > -1; pIndex--, qIndex--) {
            if (pList.get(pIndex).val == qList.get(qIndex).val) {
                answer = pList.get(pIndex);
            }
        }

        return answer;
    }

    private ArrayList<TreeNode> getDfsList(TreeNode root, TreeNode target) {
        Stack<TreeNode> stk = new Stack<>();
        HashSet<TreeNode> isVisited = new HashSet<>();
        ArrayList<TreeNode> result = new ArrayList<>();

        stk.push(root);

        if (stk.peek() != target) {
            while (!stk.empty()) {
                TreeNode top = stk.peek();

                if (top.left != null && !isVisited.contains(top.left)) {
                    isVisited.add(top.left);
                    stk.push(top.left);
                }

                if (stk.peek() == top) {
                    if (top.right != null && !isVisited.contains(top.right)) {
                        isVisited.add(top.right);
                        stk.push(top.right);
                    }
                }

                if (stk.peek() == target) {
                    break;
                }

                if (stk.peek() == top) {
                    stk.pop();
                }
            }
        }

        while (!stk.empty()) {
            result.add(stk.pop());
        }

        return result;
    }
}

public class Main {

    public static void main(String[] args) {
        TreeNode A = new TreeNode(3);
        TreeNode B = new TreeNode(5);
        TreeNode C = new TreeNode(1);
        TreeNode D = new TreeNode(6);
        TreeNode E = new TreeNode(2);
        TreeNode F = new TreeNode(0);
        TreeNode G = new TreeNode(8);
        TreeNode H = new TreeNode(7);
        TreeNode I = new TreeNode(4);

        TreeNode p = D;
        TreeNode q = F;

        A.left = B;
        A.right = C;

        B.left = D;
        B.right = E;

        C.left = F;
        C.right = G;

        E.left = H;
        E.right = I;

        System.out.println(new Solution().lowestCommonAncestor(A, p, q).val);
    }
}