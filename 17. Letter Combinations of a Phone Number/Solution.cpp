class Solution
{
private:
    void backtrack(const string digits, const string mapping[], const string newCombination, const int index, vector<string> &possibleCombinations)
    {
        if (index == digits.length())
        {
            possibleCombinations.push_back(newCombination);
            return;
        }

        for (char ch : mapping[digits[index] - '0'])
            backtrack(digits, mapping, newCombination + ch, index + 1, possibleCombinations);
    }

public:
    vector<string> letterCombinations(const string digits)
    {
        vector<string> possibleCombinations;

        if (!digits.length())
            return possibleCombinations;

        string mapping[] = {"",
                            "",
                            "abc",
                            "def",
                            "ghi",
                            "jkl",
                            "mno",
                            "pqrs",
                            "tuv",
                            "wxyz"};

        backtrack(digits, mapping, "", 0, possibleCombinations);
        return possibleCombinations;
    }
};
