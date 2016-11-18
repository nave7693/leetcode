// https://leetcode.com/problems/sum-of-left-leaves/

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
    void traverse(TreeNode* node, bool goingLeft, int *result) {
        if (!node) {
            return;
        } else {
            traverse(node->left, true, result);
            if (goingLeft && !node->left && !node->right) {
                *result = *result + node->val;
            }
            traverse(node->right, false, result);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        result = 0;
        traverse(root, false, &result);
        return result;
    }
private:
    int result;
};