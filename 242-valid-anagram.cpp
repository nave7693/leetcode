// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() == 0 && t.size() == 0) {
            return true;
        } else if (s.size() != t.size()) {
            return false;
        } else {
            int letters[26] = {0};
            for (int i = 0; i < s.size(); i++) {
                letters[s[i] - 'a']++;
            }
            int lettert[26] = {0};
            for (int i = 0; i < t.size(); i++) {
                lettert[t[i] - 'a']++;
            }
            bool result = true;
            for (int i = 0; i < sizeof(letters)/sizeof(int); i++) {
                if (letters[i] != lettert[i]) {
                    result = false;
                }
            }
            return result;
        }
    }
};