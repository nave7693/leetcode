// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (amount == 0) return 0;
        if (n == 0) return -1;
        
        // dp[i] = minimum amount of coins for i
        vector<int> dp(amount+1, 0);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i && dp[i-coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i-coins[j]] + 1, dp[i]);                    
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};