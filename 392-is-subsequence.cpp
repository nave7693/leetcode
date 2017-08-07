// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if (tlen < slen) return false;
        
        auto smatch = s.begin();
        auto tmatch = t.begin();
        while (smatch != s.end() && tmatch != t.end()) {
            if (*smatch - *tmatch == 0) {
                smatch++;
                if (smatch == s.end()) return true;
            }
            tmatch++;
        }
        return smatch == s.end();
    }
};