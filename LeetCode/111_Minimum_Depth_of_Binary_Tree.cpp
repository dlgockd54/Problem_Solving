/**
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 *
 * Note: A leaf is node with no children.
 *
 * Example:
 * Given binary tree [3, 9, 20, null, null, 15, 7],
 *
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *
 * return its minimum depth = 2.
 */

/**
 * Definition of TreeNode
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

queue<pair<TreeNode *, int> > q;

class Solution {
public:
    void clearQ() {
        while (!q.empty()) {
            q.pop();
        }
    }

    int minDepth(TreeNode *root) {
        int minDepth = 0;

        clearQ();

        if (root != nullptr) {
            minDepth = 1;
            q.push(make_pair(root, 1));

            while (!q.empty()) {
                TreeNode *x = q.front().first;
                int depth = q.front().second;

                if (x->left == nullptr && x->right == nullptr) {
                    if (minDepth == 1) {
                        minDepth = depth;
                    } else {
                        minDepth = minDepth < depth ? minDepth : depth;
                    }
                } else {
                    if (x->left != nullptr) {
                        q.push(make_pair(x->left, depth + 1));
                    }

                    if (x->right != nullptr) {
                        q.push(make_pair(x->right, depth + 1));
                    }
                }

                q.pop();
            }
        } else {
            minDepth = 0;
        }

        return minDepth;
    }
};

int main() {
    TreeNode *A = (TreeNode *) malloc(sizeof(TreeNode));
    TreeNode *B = (TreeNode *) malloc(sizeof(TreeNode));
    TreeNode *C = (TreeNode *) malloc(sizeof(TreeNode));
    TreeNode *D = (TreeNode *) malloc(sizeof(TreeNode));
    TreeNode *E = (TreeNode *) malloc(sizeof(TreeNode));

    A->val = 3;
    A->left = B;
    A->right = C;

    B->val = 9;
//    B->left = nullptr;
//    B->right = nullptr;
    B->left = D;
    B->right = E;

    C->val = 20;
//    C->left = D;
//    C->right = E;
    C->left = nullptr;
    C->right = nullptr;

    D->val = 15;
    D->left = nullptr;
    D->right = nullptr;

    E->val = 7;
    E->left = nullptr;
    E->right = nullptr;

    Solution sol = Solution();

    printf("%d\n", sol.minDepth(A));

    free(A);
    free(B);
    free(C);
    free(D);
    free(E);

    return 0;
}