// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> seen1;
        for (int i = 0; i < nums1.size(); i++) {
            if (seen1.find(nums1[i]) != seen1.end()) {
                seen1[nums1[i]]++;
            } else {
                seen1[nums1[i]] = 1;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if ((seen1.find(nums2[i]) != seen1.end()) &&
                (seen1[nums2[i]] > 0)) {
                result.push_back(nums2[i]);
                seen1[nums2[i]]--;
            }
        }
        return result;
    }
};