class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int max_letter = 1;
        int max_length = 1;

        int letters[26] = {0};
        int s_size = s.size();

        int i = 0;

        for (int j = 0; j < s_size; ++j)
        {
            max_letter = max(max_letter, ++letters[s[j] - 'A']);

            while (j - i - max_letter + 1 > k)
                --letters[s[i++] - 'A'];

            max_length = max(max_length, j - i + 1);
        }

        return max_length;
    }
};
