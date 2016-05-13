// https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while (n > 0) {
            result.insert(result.begin(), 'A' + ((n - 1) % 26));
            n = (n - 1) / 26;
        }
        return result;
    }
};