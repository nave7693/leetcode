// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        } else {
            vector<int> currentMax(nums.size());
            currentMax[0] = nums[0];
            currentMax[1] = max(nums[0], nums[1]);
            for (int i = 2; i < nums.size(); i++) {
                currentMax[i] = max(currentMax[i-1], currentMax[i-2] + nums[i]);
            }
            return currentMax[nums.size() - 1];
        }
    }
};

// 7/29
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return 0; }
        if (n == 1) { return nums[0]; }
        
        vector<int> rob(n+1, 0);
        rob[0] = 0;
        rob[1] = nums[0];
        for (int i = 2; i <=n; i++) {
            rob[i] = max(rob[i-1], rob[i-2] + nums[i-1]);
        }
        return rob[n];
    }
};