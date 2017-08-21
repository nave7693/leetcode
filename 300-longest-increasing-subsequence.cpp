// https://leetcode.com/problems/longest-increasing-subsequence

// normal DP, O(n^2)
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

// 08/20/2017 when the number is greater than everything in res, insert, otherwise find the position
// where the number is just greater than all previous numbers and replace the original number there
// Uses binary search to find the position fast
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}