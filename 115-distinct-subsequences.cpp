// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        
        vector<vector<int>> dp(lent+1, vector<int>(lens+1, 0));
        // For an empty t, any s would need to delete all its characters, if any, to achieve t
        for (int j = 0; j <= lens; j++) {
            dp[0][j] = 1;
        }
        for (int j = 1; j <= lens; j++) {
            for (int i = 1; i <= lent; i++) {
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[lent][lens];
    }
};

// space-optimized
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<int> cur(m + 1, 0);
        cur[0] = 1;
        for (int j = 1; j <= n; j++) { 
            int pre = 1;
            for (int i = 1; i <= m; i++) {
                int temp = cur[i];
                cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
                pre = temp;
            }
        }
        return cur[m];
    }
};