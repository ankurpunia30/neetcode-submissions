class Solution {
public:
    vector<vector<char>> b;

    bool checkRow(int i, int j) {
        char val = b[i][j];
        for (int col = 0; col < 9; col++) {
            if (b[i][col] == val && col != j) {
                return false;
            }
        }
        return true;
    }

    bool checkCol(int i, int j) {
        char val = b[i][j];
        for (int row = 0; row < 9; row++) {
            if (b[row][j] == val && row != i) {
                return false;
            }
        }
        return true;
    }

    bool checkMatrix(int i, int j) {
        char val = b[i][j];
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;

        for (int row = startRow; row < startRow + 3; row++) {
            for (int col = startCol; col < startCol + 3; col++) {
                if (b[row][col] == val && (row != i || col != j)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        b = board;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') continue;
                if (!checkRow(i, j) || !checkCol(i, j) || !checkMatrix(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};
