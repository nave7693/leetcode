// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result(0);
        if (root != nullptr) {
            deque<TreeNode*> traversal;
            traversal.push_back(root);
            result.push_back(vector<int>(1, root->val));
            while (!traversal.empty()) {
                vector<int> thisLevel(0);
                int levelSize = result.back().size();
                while (levelSize != 0) {
                    TreeNode* current = traversal.front();
                    traversal.pop_front();
                    levelSize--;
                    if (current->left != nullptr) {
                        traversal.push_back(current->left);
                        thisLevel.push_back(current->left->val);
                    }
                    if (current->right != nullptr) {
                        traversal.push_back(current->right);
                        thisLevel.push_back(current->right->val);
                    }
                }
                if (thisLevel.size() > 0) {
                    result.push_back(thisLevel);
                }
            }
        }
        return result;
    }
};