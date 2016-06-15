// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};