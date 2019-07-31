/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int solution(TreeNode* node, int depth) {
		int maxDepth = depth;

		if(node != nullptr) {
			int leftDepth = depth + 1;
			int rightDepth = depth + 1;

			if(node->left != nullptr) {
				leftDepth = solution(node->left, leftDepth);
			}

			if(node->right != nullptr) {
				rightDepth = solution(node->right, rightDepth);
			}

			maxDepth = leftDepth > rightDepth ? leftDepth : rightDepth;
		}
		else {
			maxDepth = depth;
		}

		return maxDepth;
	}

	int maxDepth(TreeNode* root) {
		int leftDepth = 1;
		int rightDepth = 1;

		if(root != nullptr) {
			leftDepth = solution(root->left, 1);
			rightDepth = solution(root->right, 1);
			
			return leftDepth > rightDepth ? leftDepth : rightDepth;
		}
		else {
			return 0;
		}
	}
};