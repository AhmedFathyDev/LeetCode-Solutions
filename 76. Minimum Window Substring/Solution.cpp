class Solution
{
private:
    bool is_s_contains_t(vector<int> s_letters, vector<int> t_letters)
    {
        for (int i = 0; i < 123; ++i)
            if (s_letters[i] < t_letters[i])
                return false;

        return true;
    }

public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if (m < n)
            return "";

        vector<int> s_letters(123, 0);
        vector<int> t_letters(123, 0);

        for (int i = 0; i < n; ++i)
            ++t_letters[t[i]];

        int j = 0;
        int k = 0;
        int l = -1;

        int max_k = 0;
        int min_size = INT_MAX;

        for (int i = 0; i < m; ++i)
        {
            ++s_letters[s[i]];

            while (is_s_contains_t(s_letters, t_letters))
            {
                k = max(k, j);
                l = i;

                if (l - k + 1 < min_size)
                {
                    max_k = k;
                    min_size = l - k + 1;
                }

                --s_letters[s[j]];
                ++j;
            }
        }

        return l == -1 ? "" : s.substr(max_k, min_size);
    }
};
