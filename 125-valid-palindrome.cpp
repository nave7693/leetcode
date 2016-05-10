// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int front = 0;
        int back = s.size() - 1;
        while (front < back) {
            while (front < back && !isLetter(s[front])) {
                front++;
            }
            while (front < back && !isLetter(s[back])) {
                back--;
            }
            if (tolower(s[front]) != tolower(s[back])) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};