class Solution
{
private:
    bool exist(vector<vector<char>> &board, string word, int y, int x, int i)
    {
        if (i == word.size())
            return true;

        if (y < 0 || x < 0 || y == board.size() || x == board[y].size())
            return false;

        if (board[y][x] != word[i])
            return false;

        board[y][x] = '*';
        bool found = exist(board, word, y, x + 1, i + 1) ||
                     exist(board, word, y, x - 1, i + 1) ||
                     exist(board, word, y + 1, x, i + 1) ||
                     exist(board, word, y - 1, x, i + 1);
        board[y][x] = word[i];

        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        for (int y = 0; y < rows; ++y)
            for (int x = 0; x < cols; ++x)
                if (exist(board, word, y, x, 0))
                    return true;

        return false;
    }
};
