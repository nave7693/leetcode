// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // KEY: incrementing n-1 elements by 1 is decrementing one element by 1
        int minimum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            minimum = min(nums[i], minimum);
            sum += nums[i];
        }
        return sum - (minimum * nums.size());
    }
};