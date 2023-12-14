class Solution
{
public:
    bool isPalindrome(string s)
    {
        s.erase(remove_if(s.begin(), s.end(), is_not_alphanumeric), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        return s == rev_s;
    }

    static bool is_not_alphanumeric(char c)
    {
        return !(isalpha(c) || isalnum(c));
    }
};
