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