// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            result = max(result, dp[i][0]);
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = matrix[0][i] - '0';
            result = max(result, dp[0][i]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result * result;
    }
};

// Optimize by storing only two columns
int maximalSquare(vector<vector<char>>& matrix) {
	int m = matrix.size();
	if (!m) return 0;
	int n = matrix[0].size();
	vector<int> pre(m, 0);
	vector<int> cur(m, 0);
	int maxsize = 0;
	for (int i = 0; i < m; i++) {
		pre[i] = matrix[i][0] - '0';
		maxsize = max(maxsize, pre[i]);
	}
	for (int j = 1; j < n; j++) {
		cur[0] = matrix[0][j] - '0';
		maxsize = max(maxsize, cur[0]);
		for (int i = 1; i < m; i++) {
			if (matrix[i][j] == '1') {
				cur[i] = min(cur[i - 1], min(pre[i - 1], pre[i])) + 1;
				maxsize = max(maxsize, cur[i]);
			}
		}
		swap(pre, cur);
		fill(cur.begin(), cur.end(), 0);
	}
	return maxsize * maxsize;
}

// Optimize further by storing only the previous column/row
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(m + 1, 0);
    int maxsize = 0, pre = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            int temp = dp[i];
            if (matrix[i - 1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                maxsize = max(maxsize, dp[i]);
            }
            else dp[i] = 0; 
            pre = temp;
        }
    }
    return maxsize * maxsize;
}
