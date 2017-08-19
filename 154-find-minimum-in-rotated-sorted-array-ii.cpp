// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 0) return -1;
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else if (nums[mid] < nums[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return nums[lo];
    }
};