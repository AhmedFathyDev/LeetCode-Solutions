class Trie
{
private:
    Trie *children[26];
    bool isLeaf;

public:
    Trie()
    {
        memset(children, 0, sizeof(children));
        isLeaf = false;
    }

    void insert(string word)
    {
        if (word == "")
            isLeaf = true;
        else
        {
            int currentChar = word[0] - 'a';

            if (children[currentChar] == 0)
                children[currentChar] = new Trie();

            children[currentChar]->insert(word.substr(1));
        }
    }

    bool search(string word)
    {
        if (word == "")
            return isLeaf;

        int currentChar = word[0] - 'a';

        if (children[currentChar] == 0)
            return false;

        return children[currentChar]->search(word.substr(1));
    }

    bool startsWith(string prefix)
    {
        if (prefix == "")
            return true;

        int currentChar = prefix[0] - 'a';

        if (children[currentChar] == 0)
            return false;

        return children[currentChar]->startsWith(prefix.substr(1));
    }
};
