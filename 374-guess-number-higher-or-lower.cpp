// https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int minResult = 0;
        int maxResult = n;
        int currentGuess = 0;
        int myguess = 0;
        do {
            currentGuess = minResult + ((maxResult - minResult) / 2);
            myguess = guess(minResult + (maxResult - minResult) / 2);
            if (myguess == -1) {
                maxResult = currentGuess - 1;
            } else if (myguess == 1) {
                minResult = currentGuess + 1;
            }
        } while (myguess != 0);
        return currentGuess;
    }
};