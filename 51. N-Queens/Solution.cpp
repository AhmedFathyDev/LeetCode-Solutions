class Solution
{
private:
    void backtrack(vector<string> &nQueens, vector<vector<string>> &possiblePositions, const int n, const int row)
    {
        if (row == n)
        {
            possiblePositions.push_back(nQueens);
            return;
        }

        for (int col = 0; col < n; ++col)
            if (isValidPosition(nQueens, n, row, col))
            {
                nQueens[row][col] = 'Q';
                backtrack(nQueens, possiblePositions, n, row + 1);
                nQueens[row][col] = '.';
            }
    }

    bool isValidPosition(const vector<string> &nQueens, const int n, const int row, const int col)
    {
        for (int i = 0; i < row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;

        // check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;

        // check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;

        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> nQueens(n, string(n, '.'));
        vector<vector<string>> possiblePositions;

        backtrack(nQueens, possiblePositions, n, 0);

        return possiblePositions;
    }
};
