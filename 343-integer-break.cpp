// https://leetcode.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        } else if (n % 3 == 0) {
            return (int)pow(3, (n / 3));
        } else if (n % 3 == 1) {
            return 2 * 2 * (int)pow(3, (n - 4) / 3);
        } else {
            return 2 * (int)pow(3, (n / 3));
        }
    }
};

// 8/3
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        product *= n;
        return product;
    }
};