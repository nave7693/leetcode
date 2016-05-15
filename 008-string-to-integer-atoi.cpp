// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) {
            return 0;
        }
        int index = 0;
        while (str[index] == ' ') {
            index++;
        }
        bool positive = true;
        if (str[index] == '+') {
            index++;
        } else if (str[index] == '-') {
            positive = false;
            index++;
        } else if (str[index] < '0' || str[index] > '9') {
            return 0;
        }
        int result = 0;
        while ((str[index] >= '0') && (str[index] <= '9')) {
            if (result < (INT_MAX/10) || (result == (INT_MAX/10) && (str[index] - '0') <= (INT_MAX%10))) {
                result = result * 10 + (str[index] - '0');
                index++;
            } else {
                return positive ? INT_MAX : INT_MIN;
            }
        }
        return positive ? result : -result;
    }
};