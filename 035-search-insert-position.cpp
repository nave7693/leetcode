// https://leetcode.com/problems/search-insert-position/

// WHAT! THIS IS NOT BINARY SEARCH!?
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (target <= nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
};

// 08/16/2017
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};