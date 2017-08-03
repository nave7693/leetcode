// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
private:
    vector<vector<int>> mySums;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            if (n > 0) {
                for (int i = 0; i < m; i++) {
                    mySums.push_back(vector<int>(0));
                    int prev = 0; // the sum of all elements to the left of this row
                    for (int j = 0; j < n; j++) {
                        prev += matrix[i][j];
                        mySums[i].push_back(((i == 0) ? 0 : mySums[i-1][j]) + prev);
                    }
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = (row1 == 0) ? 0 : mySums[row1 - 1][col2];
        int left = (col1 == 0) ? 0 : mySums[row2][col1-1];
        int topleft = (row1 == 0 || col1 == 0) ? 0 : mySums[row1 - 1][col1 - 1];
        return mySums[row2][col2] - top - left + topleft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
 
 // The better solution is to pad mySums with a row and column of zeros.