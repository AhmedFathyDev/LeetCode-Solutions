class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int p_size = p.size();
        int s_size = s.size();

        if (s_size < p_size)
            return {};

        vector<int> p_letters(26, 0);
        vector<int> s_letters(26, 0);

        for (int i = 0; i < p_size; ++i)
        {
            ++p_letters[p[i] - 'a'];
            ++s_letters[s[i] - 'a'];
        }

        vector<int> indices;
        if (s_letters == p_letters)
            indices.push_back(0);

        for (int i = p_size; i < s_size; ++i)
        {
            ++s_letters[s[i] - 'a'];
            --s_letters[s[i - p_size] - 'a'];

            if (s_letters == p_letters)
                indices.push_back(i - p_size + 1);
        }

        return indices;
    }
};
