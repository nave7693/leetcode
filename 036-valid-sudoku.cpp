// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValid(vector<char> &unit) {
        bool seen[9] = {};
        for (int i = 0; i < unit.size(); i++) {
            if (unit[i] == '.') {
                continue;
            } else if (unit[i] >= '1' && unit[i] <= '9' && !seen[unit[i] - '1']) {
                seen[unit[i] - '1'] = true;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            // check rows
            if (!isValid(board[i])) {
                return false;
            }
            // check columns
            vector<char> column;
            for (int j = 0; j < board[i].size(); j++) {
                column.push_back(board[j][i]);
            }
            if (!isValid(column)) {
                return false;
            }
        }
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                vector<char> block;
                for (int k = 0; k < 9; k++) {
                    block.push_back(board[i + k / 3][j + k % 3]);
                }
                if (!isValid(block)) {
                    return false;
                }
            }
        }
        return true;
    }
};