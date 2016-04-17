// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry) {
                digits[i]++;
                carry = false;
            }
            if (digits[i] > 9) {
                carry = true;
                digits[i] = digits[i] % 10;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};