// https://leetcode.com/problems/search-in-rotated-sorted-array/

// really dumb solution that does one extra binary search when the array is rotated... can just do it in one binary search
// by looking at which half-segment is ordered, and if the target is between the min/max of the ordered segment, use that
// segment, otherwise use the unordered segment.

class Solution {
public:
    int binarySearch(vector<int> & nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    
    int binarySearchForWrap(vector<int> &nums, int left, int right) {
        while (left < (right - 1)) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[0]) {
                right = mid;
            } else if (nums[mid] > nums[0]) {
                left = mid;
            }
        }
        return right;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        } else if (nums.size() == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return binarySearch(nums, 0, nums.size() - 1, target);
        } else {
            int wrap = binarySearchForWrap(nums, 0, nums.size() - 1);
            if (target < nums[0]) {
                return binarySearch(nums, wrap, nums.size() - 1, target);
            } else if (target > nums[0]) {
                return binarySearch(nums, 0, wrap - 1, target);
            } else {
                return 0;
            }
        }
    }
};

// 8/15/2017
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return mid;
            
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
};