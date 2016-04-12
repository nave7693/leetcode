// https://leetcode.com/problems/balanced-binary-tree/

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
    int getDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            int depthLeft = getDepth(node->left);
            int depthRight = getDepth(node->right);
            
            if (depthLeft == -1 || depthRight == -1) {
                return -1;
            }
            if (abs(depthLeft - depthRight) > 1) {
                return -1;
            }
            return 1 + max(getDepth(node->left), getDepth(node->right));
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return getDepth(root) != -1;
        }
    }
};