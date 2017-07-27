// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lnums = nums.size();
        if (lnums == 0) return 0;
        
        vector<int> sums(lnums, 0);
        sums[0] = nums[0];
        int maxSum = nums[0];
        
        for (int i = 0; i < lnums; i++) {
            sums[i] = max(sums[i-1] + nums[i], nums[i]);
            maxSum = max(sums[i], maxSum);
        }
        return maxSum;
    }
};