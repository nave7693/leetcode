// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr) {
            return nullptr;
        }
        if (p == q) {
            return p;
        }
        
        return checkCommonAncestor(root, p, q);
    }
private:
    TreeNode* checkCommonAncestor(TreeNode* currNode, TreeNode* p, TreeNode* q) {
        if (currNode == nullptr) {
            return nullptr;
        }
        if (currNode == p || currNode == q) {
            return currNode;
        }
        TreeNode* left = checkCommonAncestor(currNode->left, p, q);
        TreeNode* right = checkCommonAncestor(currNode->right, p, q);
        
        if (left != nullptr && right != nullptr) {
            return currNode;
        }
        return (left == nullptr) ? right : left;
    }
};