// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        if (n <= 2) return max(0, prices[1] - prices[0]);
        
        int buy = INT_MIN, sell = 0, prev_buy = INT_MIN, prev_sell = 0;
        for (int i = 0; i < n; i++) {
            buy = max(prev_buy, prev_sell - prices[i]);
            prev_buy = buy;
            prev_sell = sell;
            sell = max(prev_buy + prices[i], prev_sell);
        }
        return sell;
    }
};