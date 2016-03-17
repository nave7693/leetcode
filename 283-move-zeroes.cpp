// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        
        size_t nextIndex = 0;
        bool hasNonZeros = false;

        for (size_t searchIndex = 0; searchIndex < nums.size(); searchIndex++) {
            if (nums[searchIndex] != 0) {
                hasNonZeros = true;
                nums[nextIndex] = nums[searchIndex];
                nextIndex++;
            }
        }
        if (hasNonZeros) {
            while (nextIndex < nums.size()) {
                nums[nextIndex] = 0;
                nextIndex++;
            }
        }
    }
};