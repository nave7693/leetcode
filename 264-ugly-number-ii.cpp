// https://leetcode.com/problems/ugly-number-ii

// Time limit exceeded
class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<int> pastNumbers;
        pastNumbers.insert(1);
        int curr = 2;
        while (pastNumbers.size() < n) {
            if (curr % 2 == 0 && pastNumbers.count(curr / 2) ||
                curr % 3 == 0 && pastNumbers.count(curr / 3) ||
                curr % 5 == 0 && pastNumbers.count(curr / 5)) {
                pastNumbers.insert(curr);
            }
            curr++;
        }
        return curr-1;
    }
};

// This one directly skips to the next ugly number without checking everything in between
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) return 0;
        vector<int> pastNumbers(n);
        pastNumbers[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0, i = 1;
        for (int i = 1; i < n; i++) {
            pastNumbers[i] = min(pastNumbers[i2]*2, min(pastNumbers[i3]*3, pastNumbers[i5]*5));
            if (pastNumbers[i] == pastNumbers[i2]*2) i2++;
            if (pastNumbers[i] == pastNumbers[i3]*3) i3++;
            if (pastNumbers[i] == pastNumbers[i5]*5) i5++;
        }
        return pastNumbers[n-1];
    }
};
