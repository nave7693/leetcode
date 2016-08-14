// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        if (!root) {
            return results;
        }

        stack<TreeNode*> reserves;
        
        TreeNode* current;
        reserves.push(root);
        while (!reserves.empty()) {
            current = reserves.top();
            reserves.pop();
            results.push_back(current->val);
            if (current->right) {
                reserves.push(current->right);
            }
            if (current->left) {
                reserves.push(current->left);
            }
        }
        return results;
    }
};