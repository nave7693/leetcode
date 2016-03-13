// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() == 0 && t.size() == 0) {
            return true;
        }
        if (s.size() != t.size()) {
            return false;
        }
        char subs[CHAR_MAX] = {0};
        bool seen[CHAR_MAX] = {0};
        for (int i = 0; i < s.size(); i++) {
            int mapindex = s[i];
            if (subs[mapindex] == 0) {
                if (seen[t[i]]) {
                    return false;
                } else {
                    subs[mapindex] = t[i];
                    seen[t[i]] = true;
                }
            } else if (subs[mapindex] != t[i]) {
                return false;
            }
        }
        return true;
    }
};