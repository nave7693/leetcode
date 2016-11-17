// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> seen;
        for (int i = 0; i < s.size(); i++) {
            seen[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            seen[t[i]]--;
            if (seen[t[i]] < 0) {
                return t[i];
            }
        }
        return ' ';
    }
};