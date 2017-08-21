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

// 8/20/2017 using the node count from left and right subtrees to figure out which side to go.
// O(logn^2) since every level requires a log(n) count and cuts the problem size in half every level
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
        int count = countNodes(root->left);
        if (k <= count) {
            return kthSmallest(root->left, k);
        } else if (k > count + 1) {
            return kthSmallest(root->right, k-(count + 1)); // 1 is counted as current node
        }
        
        return root->val;
    }
private:
    int countNodes(TreeNode* n) {
        if (n == nullptr) return 0;
        
        return 1 + countNodes(n->left) + countNodes(n->right);
    }        
};