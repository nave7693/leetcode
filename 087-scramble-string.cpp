// https://leetcode.com/problems/scramble-string

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int slen = s1.length();
        if (slen == 0) return true;
        if (slen == 1) return s1 == s2;
        
        // dp[len][i][j] = whether s1[i..i+len-1] can be scrambled to become s2[j..j+len-1]
        bool dp[slen+1][slen][slen];
        
        // All length 1 scrambles (which just means whether the chars equal)
        for (int i = 0; i < slen; i++) {
            for (int j = 0; j < slen; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        
        // For all length 2+ scrambles
        for (int len = 2; len <= slen; len++) {
            for (int i = 0; i <= slen - len; i++) {
                for (int j = 0; j <= slen - len; j++) {
                    dp[len][i][j] = false;
                    for (int k = 1; k < len; k++) {
                        // first k chars of s1 and first k chars of s2 are scrambles, the rest of s1 and the rest of s2 are scrambles
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len-k][i+k][j+k]);
                        // last k chars of s1 and first k chars of s2 are scrambles, the front len-k chars of s1 and the back len-k chars of s2 are too
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i+len-k][j] && dp[len-k][i][j+k]);
                    }
                }
            }
        }
        return dp[slen][0][0];
    }
};