// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return false;
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi]) {
                hi = mid;                
            } else {
                lo = mid + 1;
            }
        }
        return nums[lo];
    }
};