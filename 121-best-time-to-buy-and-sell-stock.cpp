// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) { return 0; }
        int lowestPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowestPrice) {
                lowestPrice = prices[i];
                continue;
            } else {
                profit = max(prices[i] - lowestPrice, profit);
            }
        }
        return profit;
    }
};