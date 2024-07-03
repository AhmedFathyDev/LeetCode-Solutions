class Solution
{
private:
    bool isPalindrome(const string s, int start, int end)
    {
        while (start < end)
            if (s[start++] != s[end--])
                return false;

        return true;
    }

    void backtrack(vector<vector<string>> &possibleSubsets, vector<string> newSubsets, string s, int start)
    {
        if (start == s.size())
            possibleSubsets.push_back(newSubsets);
        else
            for (int i = start; i < s.size(); ++i)
            {
                if (!isPalindrome(s, start, i))
                    continue;

                newSubsets.push_back(s.substr(start, i + 1 - start));
                backtrack(possibleSubsets, newSubsets, s, i + 1);
                newSubsets.pop_back();
            }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> possibleSubsets;
        backtrack(possibleSubsets, {}, s, 0);
        return possibleSubsets;
    }
};
