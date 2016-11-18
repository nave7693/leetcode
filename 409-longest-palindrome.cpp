// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> seen;
        for (int i = 0; i < s.size(); i++) {
            seen[s[i]]++;
        }
        int count = 0;
        int centerFound = false;
        for (auto iter = seen.begin(); iter != seen.end(); iter++) {
            count += iter->second / 2 * 2;
            if (iter->second % 2 != 0 && !centerFound) {
                count++;
                centerFound = true;
            }
        }
        return count;
    }
};