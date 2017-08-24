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

// 08/22/2017 similar solution with linear run time
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};