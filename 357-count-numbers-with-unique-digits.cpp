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

// 8/3
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int prev = 9; // number of unique digits that can start a number of length 1
        int sum = 10;
        int curr;
        for (int i = 2; i <= min(10, n); i++) {
            // for each of the numbers in prev, we can pick a new unique digit and attach to the end
            // in the case of the second digit, we can still choose 9 because the first digit can only
            // be one of nine choices (no zero).
            curr = prev * (10-i+1);
            sum += curr;
            prev = curr;
        }
        return sum;
    }
};