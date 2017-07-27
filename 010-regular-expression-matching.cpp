// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        
        // matched[i][j] = s[0..i-1] matched p[0..j-1] ? true : false
        vector<vector<bool>> matched(ls+1, vector<bool>(lp+1, false));
        
        matched[0][0] = true;
        // whenever there is a '*' it matches the empty string.
        // just need to check every other char since there needs to be something that's not '*' preceeding a '*'
        for (int j = 1; j < lp && p[j] == '*'; j+=2) {
            matched[0][j+1] = true;
        }
        
        for (int i = 1; i <= ls; i++) {
            for (int j = 1; j <= lp; j++) {
                // current char always matches in these situations, then it depends on the result from last char
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    matched[i][j] = matched[i-1][j-1];
                // current char is '*', then we either:
                // - match s to p without the '<char>*' (repeat zero times)
                // - match s-1 to p, and the next char matches the thing in front of '*' (can be either that char or '.')
                } else if (j > 1 && p[j-1] == '*') {
                    matched[i][j] = matched[i][j-2] || (matched[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2]));
                }
            }
        }
        
        return matched[ls][lp];
    }
};