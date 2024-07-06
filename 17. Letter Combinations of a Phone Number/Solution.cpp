class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
            return {};

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

        queue<string> answers;

        answers.push("");

        while (answers.front().length() != digits.length())
        {
            string remove = answers.front();
            answers.pop();

            for (char c : mapping[digits[remove.length()] - '0'])
                answers.push(remove + c);
        }

        vector<string> possibleAnswers;

        while (answers.size())
            possibleAnswers.push_back(answers.front()), answers.pop();

        return possibleAnswers;
    }
};
