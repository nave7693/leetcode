// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        vector<int> dp(n, 0);
        
        int maxCount = 1;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                int check = nums[j] < nums[i] ? dp[j] + 1 : 1;
                dp[i] = max(dp[i], check);
            }
            maxCount = max(maxCount, dp[i]);
        }
        return maxCount;
    }
};
