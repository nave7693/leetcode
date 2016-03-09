// https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int search = s.length() - 1;
        while (s[search] == ' ') {
            search--;
        }
        while (s[search] != ' ' && search >= 0) {
            result++;
            search--;
        }
        return result;
    }
};