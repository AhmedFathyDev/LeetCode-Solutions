class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.length())
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

            for (char ch : mapping[digits[remove.length()] - '0'])
                answers.push(remove + ch);
        }

        vector<string> possibleAnswers;

        while (answers.size())
            possibleAnswers.push_back(answers.front()), answers.pop();

        return possibleAnswers;
    }
};
