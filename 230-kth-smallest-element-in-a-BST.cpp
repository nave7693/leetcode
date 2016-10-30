// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k) {
        return search(root, &k);
    }
    
    int search(TreeNode* node, int *pk) {
        if (!node) { return -1; }
        int leftVal = search(node->left, pk);
        if (*pk == 0) { return leftVal; }
        *pk = *pk - 1;
        if (*pk == 0) { return node->val; }
        return search(node->right, pk);
    }
};