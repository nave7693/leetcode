// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        if (n == 0) return 0;
        
        // dp[i][j] = minimum health at dungeon[i-1][j-1]
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        for (int i = m-1; i>=0; i--) {
            for (int j = n-1; j>=0; j--) {
                int moveUp = dp[i+1][j] == INT_MAX ? INT_MAX : dp[i+1][j] - dungeon[i][j];
                int moveLeft = dp[i][j+1] == INT_MAX ? INT_MAX : dp[i][j+1] - dungeon[i][j];
                dp[i][j] = min(moveUp, moveLeft);
                // Knight can't die
                dp[i][j] = max(1, dp[i][j]);
            }
        }
            
        return dp[0][0];
    }
};