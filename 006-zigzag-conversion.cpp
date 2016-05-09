// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() == 0 || numRows == 1 || numRows == s.size()) {
            return s;
        }
        vector<string> subs(numRows, "");
        int sIndex = 0;
        int rIndex = 0;
        bool direction = true; // true = forward, false = backward
        while (sIndex < s.size()) {
            subs[rIndex] += s[sIndex];
            if (direction) {
                if (rIndex == numRows - 1) {
                    direction = false;
                    rIndex--;
                } else {
                    rIndex++;
                }
            } else {
                if (rIndex == 0) {
                    direction = true;
                    rIndex++;
                } else {
                    rIndex--;
                }
            }
            sIndex++;
        }
        string result = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < subs[i].size(); j++) {
                result += subs[i][j];
            }
        }
        return result;
    }
};