// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // dp[i] = number of ways to add to i that includes nums[j]
        vector<int> dp(target + 1, 0);
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                int ways;
                if (i < nums[j]) {
                    ways = 0;
                }
                if (i == nums[j]) {
                    ways = 1;
                } else {
                    ways = (i - nums[j]) < 0 ? 0 : dp[i-nums[j]];
                }
                dp[i] += ways;
            }
        }
        return dp[target];
    }
};