// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    void DFS(TreeNode* node, int depth) {
        if (node->left != nullptr) {
            DFS(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            DFS(node->right, depth + 1);
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            _maxDepth = max(depth, _maxDepth);
        }
    }

    int maxDepth(TreeNode* root) {
        _maxDepth = 0;
        if (root != nullptr) {
            DFS(root, 1);
        }
        return _maxDepth;
    }

private:    
    int _maxDepth;
};