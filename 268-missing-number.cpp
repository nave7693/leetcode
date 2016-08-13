// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (nums.size()) * (nums.size()+1) / 2;
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        return sum - numSum;
    }
};