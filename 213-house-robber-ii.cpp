// https://leetcode.com/problems/house-robber-ii

class Solution {
private:
    int robHelper(int start, int end, vector<int>& nums) {
        int prev = 0, curr = 0;
        for (int i = start; i <= end; i++) {
            int temp = max(curr, prev + nums[i]);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
public:    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return 0; }
        if (n == 1) { return nums[0]; }
        if (n == 2) { return max(nums[0], nums[1]); }
        
        int robLastButOne = robHelper(0, n-2, nums);
        int robLast = robHelper(1, n-1, nums);
        return max(robLastButOne, robLast);
    }
};