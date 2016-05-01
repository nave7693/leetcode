// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> symbols;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                symbols.push(s[i]);
            } else {
                if (symbols.empty()) return false;
                char last = symbols.top();
                if ((s[i] == ')' && last == '(') ||
                    (s[i] == ']' && last == '[') ||
                    (s[i] == '}' && last == '{')) {
                    symbols.pop();
                } else {
                    return false;
                }
            }
        }
        return symbols.empty();
    }
};