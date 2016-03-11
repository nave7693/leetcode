// https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int power = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            result += (s[i] - 'A' + 1) * power;
            power *= 26;
        }
        return result;
    }
};