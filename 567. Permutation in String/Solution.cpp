class Solution
{
private:
    bool are_arrays_equal(int *arr1, int *arr2, size_t size)
    {
        for (size_t i = 0; i < size; i++)
            if (arr1[i] != arr2[i])
                return false;

        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int s1_size = s1.size();
        int s2_size = s2.size();

        if (s2_size < s1_size)
            return false;

        int s1_letters[26] = {0};
        int s2_letters[26] = {0};

        for (char letter : s1)
            ++s1_letters[letter - 'a'];

        int i = 0;
        int j = -1;

        while (++j < s2_size)
        {
            ++s2_letters[s2[j] - 'a'];

            if (j - i + 1 == s1_size && are_arrays_equal(s1_letters, s2_letters, 26))
                return true;

            if (j - i + 1 >= s1_size)
            {
                --s2_letters[s2[i] - 'a'];
                ++i;
            }
        }

        return false;
    }
};
