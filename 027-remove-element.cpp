// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size() - 1;
        int length = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                while (nums[j] == val) {
                    j--;
                }
                if (j > i) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    length++;
                } else {
                    break;
                }
            } else {
                length++;
            }
        }
        return length;
    }
};