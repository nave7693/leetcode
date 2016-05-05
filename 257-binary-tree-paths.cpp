// https://leetcode.com/problems/binary-tree-paths/

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
    void traverse(TreeNode* node, string path) {
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
        } else {
            if (node->left != nullptr) {
                traverse(node->left, path + "->" + to_string(node->left->val));
            }
            if (node->right != nullptr) {
                traverse(node->right, path + "->" + to_string(node->right->val));
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        if (root != nullptr) {
            path += to_string(root->val);
            traverse(root, path);
        }
        return result;
    }

private:
    vector<string> result;
};