class WordDictionary
{
private:
    WordDictionary *children[26];
    bool isLeaf;

public:
    WordDictionary()
    {
        memset(children, 0, sizeof(children));
        isLeaf = false;
    }

    void addWord(string word)
    {
        if (word == "")
            isLeaf = true;
        else
        {
            int currentChar = word[0] - 'a';

            if (children[currentChar] == 0)
                children[currentChar] = new WordDictionary();

            children[currentChar]->addWord(word.substr(1));
        }
    }

    bool search(string word)
    {
        if (word == "")
            return isLeaf;

        if (word[0] != '.')
        {
            int currentChar = word[0] - 'a';

            if (children[currentChar] == 0)
                return false;

            return children[currentChar]->search(word.substr(1));
        }

        bool isValid = false;

        for (int i = 0; i < 26; ++i)
            if (children[i] != 0 && children[i]->search(word.substr(1)))
                isValid = true;

        return isValid;
    }
};
