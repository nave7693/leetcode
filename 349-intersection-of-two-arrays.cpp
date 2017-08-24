// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen1;
        unordered_set<int> seen2;
        vector<int> result;
        
        for (int i = 0; i < nums1.size(); i++) {
            if (seen1.find(nums1[i]) == seen1.end()) {
                seen1.insert(nums1[i]);
            }
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (seen1.find(nums2[i]) != seen1.end() &&
                seen2.find(nums2[i]) == seen2.end()) {
                result.push_back(nums2[i]);
                seen2.insert(nums2[i]);
            }
        }
        return result;
    }
};

// 08/22/2017 binary search
class Solution {
private:
    bool binarySearch(int target, vector<int>& nums) {
        if (nums.size() == 0) return false;
        
        int lo = 0, high = nums.size() - 1;
        int mid;
        while (lo <= high) {
            mid = lo + ((high - lo) >> 1);
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersection(nums2, nums1);
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> result;
        int temp = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            if (temp != nums1[i] && binarySearch(nums1[i], nums2)) {
                result.push_back(nums1[i]);
            }
            temp = nums1[i];
        }
        return result;
    }
};