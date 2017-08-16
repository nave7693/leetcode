// https://leetcode.com/problems/search-for-a-range

class Solution {
private:
    // Search for the first number >= target
    int searchHelper(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>(2, -1);
        int left = searchHelper(nums, target);
        if (left == nums.size() || nums[left] != target) return vector<int>(2, -1);
        vector<int> result(2);
        result[0] = left;
        result[1] = searchHelper(nums, target+1) - 1;
        return result;
    }
};