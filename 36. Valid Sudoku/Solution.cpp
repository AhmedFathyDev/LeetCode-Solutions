class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int blocks[3][3][9] = {0};

        for (int r = 0; r < 9; ++r)
            for (int c = 0; c < 9; ++c)
                if (board[r][c] != '.')
                {
                    if (rows[r][board[r][c] - '1']++)
                        return false;
                    if (cols[c][board[r][c] - '1']++)
                        return false;
                    if (blocks[r / 3][c / 3][board[r][c] - '1']++)
                        return false;
                }

        return true;
    }
};
