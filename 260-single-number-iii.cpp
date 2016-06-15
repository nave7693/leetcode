// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    int acc(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int axorb = acc(nums);
        int rightmost1 = axorb & -axorb;
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & rightmost1) {
                result[1] ^= nums[i];
            } else {
                result[0] ^= nums[i];
            }
        }
        return result;
    }
};