public class Solution
{
    public int MinDistance(string word1, string word2)
    {
        int[,] DPTable = new int[word2.Length + 1, word1.Length + 1];

        for (int j = 1; j <= word1.Length; ++j)
        {
            DPTable[0, j] = j;
        }

        for (int i = 1; i <= word2.Length; ++i)
        {
            DPTable[i, 0] = i;
        }

        for (int i = 1; i <= word2.Length; ++i)
        {
            for (int j = 1; j <= word1.Length; ++j)
            {
                DPTable[i, j] = Math.Min(DPTable[i - 1, j] + 1, Math.Min(DPTable[i, j - 1] + 1, DPTable[i - 1, j - 1] + (word1[j - 1] == word2[i - 1] ? 0 : 1)));
            }
        }

        return DPTable[word2.Length, word1.Length];
    }
}