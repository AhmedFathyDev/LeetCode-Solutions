class Solution
{
private:
    void solveNQueens(vector<string> &nQueens, vector<vector<string>> &possiblePositions, const int n, const int row)
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
                solveNQueens(nQueens, possiblePositions, n, row + 1);
                nQueens[row][col] = '.';
            }
    }

    bool isValidPosition(const vector<string> &nQueens, const int n, const int row, const int col)
    {
        for (int i = 0; i < row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;

        return true;
    }

public:
    int totalNQueens(int n)
    {
        vector<string> nQueens(n, string(n, '.'));
        vector<vector<string>> possiblePositions;

        solveNQueens(nQueens, possiblePositions, n, 0);

        return possiblePositions.size();
    }
};
