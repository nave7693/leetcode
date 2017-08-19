// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int lo = 0, hi = nums.size() - 1;
        int mid = 0;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[hi]) {
                if (nums[lo] <= target && target < nums[mid]) hi = mid;
                else lo = mid + 1;
            } else if (nums[mid] < nums[hi]) {
                if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
                else hi = mid;
            } else {
                // nums[mid] == nums[hi]
                hi--;
            }
        }
        return nums[lo] == target ? true : false;
    }
};