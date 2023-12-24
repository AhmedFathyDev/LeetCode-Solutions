class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sk;

        for (char ch : s)
            switch (ch)
            {
            case ')':
                if (!sk.empty() && sk.top() == '(')
                    sk.pop();
                else
                    return false;
                break;
            case ']':
                if (!sk.empty() && sk.top() == '[')
                    sk.pop();
                else
                    return false;
                break;
            case '}':
                if (!sk.empty() && sk.top() == '{')
                    sk.pop();
                else
                    return false;
                break;
            default:
                sk.push(ch);
            }

        return sk.empty();
    }
};
