// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int ls = s.length();
        
        // maxleng[i] = the length of the longest valid parentheses that ends on i
        // maxleng[s.length()] may not be the longest!
        vector<int> maxleng(ls, 0);
        
        int result = 0;
        for (int i = 1; i < ls; i++) {
            if (s[i] == ')') {
                // check whether the longest valid parentheses ends on i by looking at whether
                // the char directly in front of the last longest sequence is a '(' to match this ')'
                int j = i - maxleng[i-1] - 1;
                if (j>=0 && s[j] == '(') {
                    // if so, count the two that matched, the sequence they enclose, and any sequence
                    // directly preceding the matching '('
                    maxleng[i] = 2 + maxleng[i-1] + (j>0 ? maxleng[j-1] : 0);
                }
            }
            result = max(result, maxleng[i]);
        }
        return result;
    }
};