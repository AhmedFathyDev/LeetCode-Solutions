class Trie
{
public:
    bool isLeaf;
    Trie *children[26];

    Trie()
    {
        isLeaf = false;

        for (int i = 0; i < 26; ++i)
        {
            children[i] = NULL;
        }
    }

    void insert(string word)
    {
        if (word == "")
            isLeaf = true;
        else
        {
            int currentChar = word[0] - 'a';

            if (!children[currentChar])
                children[currentChar] = new Trie();

            children[currentChar]->insert(word.substr(1));
        }
    }
};

class Solution
{
private:
    void exist(vector<vector<char>> &board, vector<string> &wordsFound, Trie *trie, string word, int y, int x)
    {
        if (trie->isLeaf)
        {
            wordsFound.push_back(word);
            trie->isLeaf = false;
        }

        if (y < 0 || x < 0 || y == board.size() || x == board[y].size())
            return;

        char currentChar = board[y][x];

        if (currentChar == '*' || !trie->children[currentChar - 'a'])
            return;

        trie = trie->children[currentChar - 'a'];
        board[y][x] = '*';

        exist(board, wordsFound, trie, word + currentChar, y, x + 1);
        exist(board, wordsFound, trie, word + currentChar, y, x - 1);
        exist(board, wordsFound, trie, word + currentChar, y + 1, x);
        exist(board, wordsFound, trie, word + currentChar, y - 1, x);

        board[y][x] = currentChar;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> wordsFound;

        Trie *trie = new Trie();

        int rows = board.size();
        int cols = board[0].size();
        int wordsSize = words.size();

        for (int i = 0; i < wordsSize; ++i)
            trie->insert(words[i]);

        for (int y = 0; y < rows; ++y)
            for (int x = 0; x < cols; ++x)
                exist(board, wordsFound, trie, "", y, x);

        return wordsFound;
    }
};
