class Solution:
    def check(self, row: int, col: int, board: List[List[str]]) -> bool:
        sudoku_value = board[row][col]

        # Checking previous cells in the row
        for j in range(col):
            if board[row][j] == sudoku_value:
                return False

        # Checking previous cells in the column
        for i in range(row):
            if board[i][col] == sudoku_value:
                return False

        # Checking previously visited cells in the 3x3 box
        r = (row // 3) * 3
        c = (col // 3) * 3

        for i in range(r, row + 1):
            for j in range(c, c + 3):
                if i == row and j >= col:
                    break

                if board[i][j] == sudoku_value:
                    return False

        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue

                if not self.check(i, j, board):
                    return False

        return True