// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        vector<vector<int>> sums(m, vector<int>(n, 0));
        sums[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    sums[i][j] = sums[i][j-1] + grid[i][j];
                } else if (j == 0) {
                    sums[i][j] = sums[i-1][j] + grid[i][j];
                } else {
                    sums[i][j] = min(sums[i][j-1], sums[i-1][j]) + grid[i][j];
                }
            }
        }
        return sums[m-1][n-1];
    }
};