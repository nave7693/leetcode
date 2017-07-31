// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int result = nums[0];
        int iMin = result;
        int iMax = result;
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(iMin, iMax);
            }
            iMin = min(iMin * nums[i], nums[i]);
            iMax = max(iMax * nums[i], nums[i]);
            result = max(result, iMax);
        }
        return result;
    }
};