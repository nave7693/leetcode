// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Maps a value seen to the index it was first seen
        map<int, int> seen;
        int minDistance = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                minDistance = min(minDistance, i - seen[nums[i]]);
                if (minDistance <= k) {
                    return true;
                }
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};