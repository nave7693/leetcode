// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = (m == 0) ? 0 : obstacleGrid[0].size();
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> paths(m, vector<int>(n, 0));
        paths[0][0] = obstacleGrid[0][0] == 1? 0 : 1;
        for (int i = 1; i < m; i++) {
            paths[i][0] = obstacleGrid[i][0] == 1? 0 : paths[i-1][0];
        }
        for (int j = 1; j < n; j++) {
            paths[0][j] = obstacleGrid[0][j] == 1? 0 : paths[0][j-1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                paths[i][j] = obstacleGrid[i][j] == 1? 0 : (paths[i-1][j] + paths[i][j-1]);
            }
        }
        return paths[m-1][n-1];
    }
};