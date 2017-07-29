// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        if (len1 + len2 != len3) {
            return false;
        }
        
        // dp[i][j] = s3[0..i+j-1] is an interleave of s1[0..i-1] and s2[0..j-1]
        int dp[len1+1][len2+1];
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                } else {
                    dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) || (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
                }
            }
        }
        return dp[len1][len2];
    }
};