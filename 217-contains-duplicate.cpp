// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }

        set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            auto numseen = seen.find(nums[i]);
            if (numseen != seen.end()) {
                return true;
            } else {
                seen.insert(nums[i]);
            }
        }
        return false;
    }
};