// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r) >> 1;
            if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / n][r % n] == target;
    }
};