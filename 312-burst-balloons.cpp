// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> maxCoins(n+2, vector<int>(n+2, 0));
        for (int len = 1; len <= n; len++) {
            // leftbound and rightbound both shifted right by one to accomodate nums
            for (int leftbound = 1; leftbound <= n - len + 1; leftbound++) {
                // there are len elements between leftbound and rightbound inclusive
                int rightbound =  leftbound + len - 1;
                int bestCoins = 0;
                for (int finalpop = leftbound; finalpop <= rightbound; finalpop++) {
                    int coins = maxCoins[leftbound][finalpop-1] + maxCoins[finalpop+1][rightbound];
                    coins += nums[leftbound-1] * nums[finalpop] * nums[rightbound+1];
                    bestCoins = max(bestCoins, coins);
                }
                maxCoins[leftbound][rightbound] = bestCoins;
            }
        }
        return maxCoins[1][n];
    }
};