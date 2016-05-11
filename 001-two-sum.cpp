// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            seen.insert(pair<int, int>(nums[i], i));
        };
        for (int j = 0; j < nums.size(); j++) {
            int toFind = target - nums[j];
            auto found = seen.equal_range(toFind);
            auto check = found.first;
            // Handle reoccuring/double-counting the same element in the array
            while (check != found.second && check->second == j) {
                check++;
            }
            if (check != found.second) {
                vector<int> result(2);
                result[0] = min(check->second, j);
                result[1] = max(check->second, j);
                return result;
            }
        }
        return vector<int>(2);
    }
};