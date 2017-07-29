// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(0);
        return generateSubTrees(1, n);
    }
    
private:
    vector<TreeNode*> generateSubTrees(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTree = generateSubTrees(start, i-1);
            vector<TreeNode*> rightTree = generateSubTrees(i+1, end);
            
            for (int l = 0; l < leftTree.size(); l++) {
                for (int r = 0; r < rightTree.size(); r++) {
                    TreeNode* newRoot = new TreeNode(i);
                    newRoot->left = leftTree[l];
                    newRoot->right = rightTree[r];
                    result.push_back(newRoot);
                }
            }
        }
        return result;
    }
};