// https://leetcode.com/problems/path-sum/

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
    bool checkPathSums(TreeNode* node, int current, int sum) {
        current += node->val;
        if (node->left != nullptr || node->right != nullptr) {
            bool result = false;
            if (node->left != nullptr) {
                result = checkPathSums(node->left, current, sum);
            }
            if (!result && node->right != nullptr) {
                result = checkPathSums(node->right, current, sum);
            }
            return result;
        } else {
            return (current == sum);
        }
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        } 
        return checkPathSums(root, 0, sum);
    }
};