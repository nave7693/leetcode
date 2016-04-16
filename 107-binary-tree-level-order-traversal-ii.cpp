// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result(0);
        if (root != nullptr) {
            deque<TreeNode*> traversal;
            result.push_back(vector<int>(1, root->val));
            traversal.push_back(root);
            while (!traversal.empty()) {
                vector<int> currentLevel(0);
                int size = traversal.size();
                TreeNode *current = traversal.front();
                while (size > 0) {
                    traversal.pop_front();
                    size--;
                    if (current->left != nullptr) {
                        traversal.push_back(current->left);
                        currentLevel.push_back(current->left->val);
                    }
                    if (current->right != nullptr) {
                        traversal.push_back(current->right);
                        currentLevel.push_back(current->right->val);
                    }
                    current = traversal.front();
                }
                if (currentLevel.size() > 0) {
                    result.insert(result.begin(), currentLevel);
                }
            }
        }
        return result;
    }
};