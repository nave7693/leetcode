// https://leetcode.com/problems/largest-number/

class Solution {
public:
    static bool compare(int num1, int num2) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s1s2 = s1 + s2;
        string s2s1 = s2 + s1;
        return (s1s2.compare(s2s1) > 0) ? true : false;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) {
            return "0";
        }
        string result = "";
        for (int i = 0; i < nums.size(); i++) {
            result = result + to_string(nums[i]);
        }
        return result;
    }
};