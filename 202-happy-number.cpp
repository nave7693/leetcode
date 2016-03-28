// https://leetcode.com/problems/happy-number/

class Solution {
public:
    int getSquareSum(int n) {
        int result = 0;
        while (n > 0) {
            result += (n % 10) * (n % 10);
            n = n / 10;
        }
        return result;
    }

    bool isHappy(int n) {
        map<int, bool> seenNum;
        
        seenNum[n] = true;
        while (n > 1) {
            n = getSquareSum(n);
            if (seenNum.find(n) != seenNum.end()) {
                return false;
            }
            seenNum[n] = true;
        }
        return true;
    }
};