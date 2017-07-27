// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int *steps = new int[n+1];
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;
        if (n > 2) {
            for (int i = 3; i <= n; i++) {
                steps[i] = steps[i-1] + steps[i-2];
            }
        }
        return steps[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n, 0);
        steps[0] = 1;
        steps[1] = 2;
        for (int i = 2; i < n; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n-1];
    }
};