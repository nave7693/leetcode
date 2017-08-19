// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2, 0);
        if (numbers.size() < 2) return result;
        int lo = 0;
        int hi = numbers.size() - 1;
        int temp;
        
        while (lo < hi) {
            temp = numbers[lo] + numbers[hi];
            if (temp == target) {
                break;
            } else if (temp < target) {
                lo++;
            } else {
                hi--;
            }
        }
        result[0] = lo+1;
        result[1] = hi+1;
        return result;
    }
};