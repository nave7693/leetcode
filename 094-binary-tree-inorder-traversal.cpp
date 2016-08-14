// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> reserves;
        vector<int> results;
        
        TreeNode* current = root;
        while (current || !reserves.empty()) {
            while (current) {
                reserves.push(current);
                current = current->left;
            }

            current = reserves.top();
            reserves.pop();
            
            results.push_back(current->val);

            current = current->right;
        }
        return results;
    }
};