// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int slen = s.length();
        if (slen == 0) return 0;
        if (slen == 1) return s[0] == '0' ? 0 : 1;
        
        // ways[i] = number of ways to decode s[0..i-1]
        int ways[slen+1];
        ways[0] = 1; // accounts for strings with length 2
        ways[1] = s[0] == '0' ? 0 : 1;
        
        for (int i = 2; i <= slen; i++) {
            ways[i] = 0;
            // first, we can decode the last char, which is basically the same number of ways to decode s[0..i-1]
            // the last char can't be decoded if it is '0' because that has to be 10 or 20
            if (s[i-1] != '0') {
                ways[i] += ways[i-1];
            }
            // Then, we can decide the last two chars, which is basically the same number of ways to decode s[0..i-2]
            // But we need to check whether the string is '1'..'26' to make sure the combination will make sense
            // Also if s[i-2] == '0' this split also makes no sense
            if (s[i-2] != '0') {
                int decoded = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                if (decoded <= 26) {
                    ways[i] += ways[i-2];
                }
            }
        }
        return ways[slen];
    }
};

// optimization with O(1) space
int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
    int r1 = 1, r2 = 1;
    
    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}