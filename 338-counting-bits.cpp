// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) {
            return vector<int>(1,0);
        }
        vector<int> dp = vector<int>(num + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};

//8/3/2017
class Solution {
public:
    vector<int> countBits(int num) {
        // dp[i] = number of bits from 1..i
        vector<int> dp(num+1, 0);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};