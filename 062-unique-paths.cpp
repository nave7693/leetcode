// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> pathcounts(n);
        pathcounts[0] = vector<int>(m, 1);
        for (int i = 1; i < n; i++) {
            pathcounts[i] = vector<int>(m, 0);
            pathcounts[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                pathcounts[i][j] = pathcounts[i-1][j] + pathcounts[i][j-1];
            }
        }
        return pathcounts[n-1][m-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    paths[i][j] = 1; // only one straight path leads here
                } else {
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
                }
            }
        }
        return paths[m-1][n-1];
    }
};