// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    int minCut(string s) {
        int slen = s.length();
        if (slen == 0) return 0;
        // dp[i] minimum cuts for 0..i
        vector<int> dp(slen + 1, 0);
        
        // Init to maximum number of cuts for s[0..i-1]
        for (int i = 0; i <= slen; i++) {
            dp[i] = i-1;
        }
        for (int i = 0; i < slen; i++) {
            // dp[right of pal] = min(dp[right of pal], mincut at dp[left of pal] + 1)
            // Check all palindromes centered at s[i] (odd lengths)
            for (int j = 0; i-j >= 0 && i+j < slen && s[i-j] == s[i+j]; j++)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j] + 1);
            // Check all palindromes centered between s[i] and s[i+1] (even lengths)
            for (int j = 1; i-j+1 >= 0 && i+j < slen && s[i-j+1] == s[i+j]; j++)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j+1] + 1);
        }
        return dp[slen];
    }
};