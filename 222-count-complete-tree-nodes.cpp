// https://leetcode.com/problems/count-complete-tree-nodes

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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        TreeNode *nleft = root, *nright = root;
        int hleft = 0, hright = 0;
        while (nleft) { nleft = nleft->left; hleft++; }
        while (nright) { nright = nright->right; hright++;}
        if (hleft == hright) return pow(2, hleft) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};