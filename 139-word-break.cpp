// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = s.length();
        
        int minWordLen = INT_MAX;
        for (int i = 0; i < wordDict.size(); i++) {
            minWordLen = min(minWordLen, (int)wordDict[i].length());
        }
        if (minWordLen > slen) return false;
        
        vector<bool> dp(slen+1, false);
        dp[0] = true;
        for (int i = 1; i <= slen; i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                int wordLen = wordDict[j].length();
                if (i < wordLen) continue;
                if (!dp[i - wordLen]) continue;
                if (s.substr(i-wordLen, wordLen) == wordDict[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[slen];
    }
};