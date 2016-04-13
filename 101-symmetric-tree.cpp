// https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// recursive solution
class Solution {
public:
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if ((left != nullptr && right == nullptr) || (right != nullptr && left == nullptr)) {
            return false;
        } else {
            return (left->val == right->val) && checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return checkSymmetric(root->left, root->right);
        }
    }
};

// iterative solution involves traversing the left tree left-to-right, right tree right-to-left, perhaps one node at a time (including null children),
// and compare each time whether the visited nodes are equal.