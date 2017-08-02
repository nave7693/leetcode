// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> dp({0});
        
        while (dp.size() <= n) {
            int maxSquare = dp.size();
            int maxCount = INT_MAX;
            for (int i = 1; i*i <= maxSquare; i++) {
                maxCount = min(maxCount, dp[maxSquare-i*i] + 1);
            }
            dp.push_back(maxCount);
        }
        return dp[n];
    }
};