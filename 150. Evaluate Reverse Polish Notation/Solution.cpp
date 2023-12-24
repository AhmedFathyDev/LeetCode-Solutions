class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> sk;

        for (string token : tokens)
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int num2 = sk.top();
                sk.pop();

                int num1 = sk.top();
                sk.pop();

                if (token == "+")
                    sk.push(num1 + num2);
                else if (token == "-")
                    sk.push(num1 - num2);
                else if (token == "*")
                    sk.push(num1 * num2);
                else if (token == "/")
                    sk.push(num1 / num2);
            }
            else
                sk.push(stoi(token));

        return sk.top();
    }
};
