// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int letterToInt(char &c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
    }

    int romanToInt(string s) {
        int result = 0;
        char pre = ' ';
        
        for (int i = 0; i < s.size(); i++) {
            int currInt = letterToInt(s[i]);
            int prevInt = letterToInt(pre);
            result += currInt;
            if (currInt > prevInt)
            {
                bool shouldSubtract = false;
                switch (pre) {
                case 'I':
                    shouldSubtract = (s[i] == 'V' || s[i] == 'X');
                    break;
                case 'X':
                    shouldSubtract = (s[i] == 'L' || s[i] == 'C');
                    break;
                case 'C':
                    shouldSubtract = (s[i] == 'D' || s[i] == 'M');
                    break;
                default:
                    break;
                }
                if (shouldSubtract) {
                    result -= 2 * prevInt;
                }
            }
            pre = s[i];
        }
        return result;
    }
};