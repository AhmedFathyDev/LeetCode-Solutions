class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int s1_size = s1.size();
        int s2_size = s2.size();

        if (s2_size < s1_size)
            return false;

        vector<int> s1_letters(26, 0);
        vector<int> s2_letters(26, 0);

        for (int i = 0; i < s1_size; ++i)
        {
            ++s1_letters[s1[i] - 'a'];
            ++s2_letters[s2[i] - 'a'];
        }

        vector<int> indices;
        if (s2_letters == s1_letters)
            return true;

        for (int i = s1_size; i < s2_size; ++i)
        {
            ++s2_letters[s2[i] - 'a'];
            --s2_letters[s2[i - s1_size] - 'a'];

            if (s2_letters == s1_letters)
                return true;
        }

        return false;
    }
};
