class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char digit) {

        for(int j = 0; j < 9; j++) {
            if(board[row][j] == digit) {
                return false;
            }
        }

        for(int i = 0; i < 9; i++) {
            if(board[i][col] == digit) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(board[i][j] == digit) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {

        if(row == 9) {
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if(nextCol == 9) {
            nextRow++;
            nextCol = 0;
        }

        if(board[row][col] != '.') {
            return solve(board, nextRow, nextCol);
        }

        for(char digit = '1'; digit <= '9'; digit++) {

            if(isSafe(board, row, col, digit)) {

                board[row][col] = digit;

                if(solve(board, nextRow, nextCol)) {
                    return true;
                }

                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};