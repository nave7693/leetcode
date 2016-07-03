class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        vector<int> result(nums.size(), 1);
        int currentProduct = 1;
        // These are the products of all numbers to the left of the current number...
        for (int i = 1; i < nums.size(); i++) {
            currentProduct *= nums[i - 1];
            result[i] = currentProduct;
        }
        currentProduct = 1;
        // Multiply by the products of all numbers to the right.
        for (int i = nums.size() - 2; i >= 0; i--) {
            currentProduct *= nums[i + 1];
            result[i] = result[i] * currentProduct;
        }
        return result;
    }
};