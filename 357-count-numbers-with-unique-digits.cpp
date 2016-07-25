// https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        }
        unsigned int result = 10;
        
        for (int i = 2; i <= n; i++) {
            unsigned int total = 9;
            // 9 - i + 1 is the number of choices at the last digit, but due to the first digit
            // being from 1-9 (9 choices), the second digit still has 9 posibilities (including zero)
            // so we can get to 9 - i + 2, so it is 9 * 9 * 8 * 7 * ... * (i - k + 2)
            for (int j = 9; j > (9 - i + 1); j--) {
                total *= j;
            }
            
            // Add the current amount of numbers with i digits to the previous sum
            result +=  total;
        }
        return result;
    }
};