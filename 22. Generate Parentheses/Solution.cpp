class Solution
{
private:
    vector<string> combinations;

    void find_combination(string combination, int open, int close, int max)
    {
        if (combination.size() == max * 2)
        {
            combinations.push_back(combination);
            return;
        }

        if (open < max)
            find_combination(combination + "(", open + 1, close, max);

        if (close < open)
            find_combination(combination + ")", open, close + 1, max);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        find_combination("", 0, 0, n);
        return combinations;
    }
};
