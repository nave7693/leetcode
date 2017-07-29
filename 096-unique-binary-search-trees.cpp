// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;
        
        // dp[i] = number of unique BSTs consisting of 0..i
        
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int root = 1; root <= i; root++) {
                // each time we pick a number from 1..i as the root of the BST, the unique way of constructing
                // a BST is the number of combinations of a unique left BST and a unique right BST. There
                // are dp[root-1] unique left BSTs and dp[i - (root-1) - 1] unique right BSTs
                dp[i] += dp[root - 1] * dp[i - root];
            }
        }
        return dp[n];
    }
};