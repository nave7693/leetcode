// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool checkfirstandlastdigit(int first, int *last) {
        if (first == 0) {
            return true;
        }
        
        if (checkfirstandlastdigit(first / 10, last)) {
            if (first % 10 == *last % 10) {
                *last /= 10;
                return true;
            }
        }
        return false;
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int last = x;
        return checkfirstandlastdigit(x, &last);
    }
};