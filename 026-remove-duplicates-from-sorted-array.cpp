// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t dupes = 0;
        if (nums.size() <= 1) {
           return nums.size();
        }
        else
        {
            size_t source = 1;
            size_t dest = 0;
            while (source < nums.size())
            {
                if (nums[dest] != nums[source])
                {
                    dest++;
                    nums[dest] = nums[source];
                }
                else
                {
                    dupes++;
                }
                source++;
            }
        }
        return nums.size() - dupes;
    }
};