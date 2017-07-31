// https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        vector<int> sums(triangle.size(), 0);
        sums[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = i; j >= 0; j--) {
                int left = (j == 0) ? INT_MAX : (triangle[i][j] + sums[j - 1]);
                int right = (j == i) ? INT_MAX : (triangle[i][j] + sums[j]);
                sums[j] = min(left, right);
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) {
            result = min(result, sums[i]);
        }
        return result;
    }
};

// 7/29
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        
        // dp[i] = minimum path sum for the current row at position i
        vector<int> dp(n+1, 0);
        
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i-1][j];
            }
        }
        return dp[0];
    }
};