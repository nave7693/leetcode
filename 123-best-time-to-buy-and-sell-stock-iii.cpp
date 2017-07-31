// 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int maxTrades = 2;
        vector<vector<int>> dp(maxTrades+1, vector<int>(n, 0));
        int result = 0;
        
        for (int k = 1; k <= maxTrades; k++) {
            // Finding the best trade involves finding the best place to buy and sell
            // Assume for now that the best place to buy is 0
            int bestbuy = dp[k-1][0] - prices[0];
            for (int i = 1; i < n; i++) {
                dp[k][i] = max(dp[k][i-1], bestbuy + prices[i]); // Compare whether to sell or not
                bestbuy = max(bestbuy, dp[k-1][i] - prices[i]); // Maybe buying now gives us a bigger profit (the lowest price point)
                result = max(result, dp[k][i]);
            }
        }
        return result;
    }
};