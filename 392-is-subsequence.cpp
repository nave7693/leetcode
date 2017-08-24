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

// 08/23/2017 using binary search to find progressively increasing positions of the chars in s
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> index;
        for (int i = 0; i < t.length(); i++) {
            if (index.count(t[i]) == 0) {
                index[t[i]] = vector<int>();
            }
            index[t[i]].push_back(i);
        }
        
        int previousPos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (index.count(s[i]) == 0) { return false;}
            auto newPos = std::lower_bound(index[s[i]].begin(), index[s[i]].end(), previousPos); // binary search
            if (newPos == index[s[i]].end()) { return false; }
            previousPos = *newPos + 1;
        }
        return true;
    }
};