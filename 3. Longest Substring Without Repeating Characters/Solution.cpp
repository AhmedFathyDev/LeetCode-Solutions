class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest_sub_string = 0;

        int chars[256];

        for (auto &ch : chars)
            ch = -1;

        int s_size = s.size();

        int i = 0;
        int j = -1;

        while (++j < s_size)
        {
            if (chars[s[j]] != -1)
                i = max(i, chars[s[j]] + 1);

            chars[s[j]] = j;
            longest_sub_string = max(longest_sub_string, j - i + 1);
        }

        return longest_sub_string;
    }
};
