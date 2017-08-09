// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        // dp[i] = is there a set of numbers from nums that can add up to i
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto num : nums) 
            for(int i = target; i >= num; i--)
                dp[i] = dp[i] || dp[i - num];
        // If there is a set of numbers from nums that can add up to sum / 2,
        // then the other numbers also sum to sum / 2
        return dp[target];
    }
};