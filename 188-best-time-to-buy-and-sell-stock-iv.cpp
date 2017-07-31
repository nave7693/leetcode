// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        if (k > n/2) {
            int result = 0;
            for (int i = 1; i < n; i++) {
                result += max(prices[i] - prices[i-1], 0);
            }
            return result;
        } else {
            // dp[k] = maximum profit doing k transactions before prices[i]
            // Cannot allocate O(kn) because of it would run out of memory
            vector<int> hold(k+1, INT_MIN);
            vector<int> sell(k+1, 0);
            for (int i = 0; i < n; i++) {
                for (int j = k; j > 0; j--) {
                    // Sell or not?
                    // sell[j] and hold[j] really holds the maximum profit from the j-1 transactions
                    sell[j] = max(sell[j] /*don't sell*/, hold[j] + prices[i] /*sell*/);
                    // Or maybe this time is the best to buy?
                    hold[j] = max(hold[j] /*hold*/, sell[j-1] - prices[i] /*don't hold*/);
                }
            }
            return sell[k];
        }
    }
};