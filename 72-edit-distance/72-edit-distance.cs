public class Solution
{
    public int MinDistance(string word1, string word2)
    {
        int[,] db = new int[word2.Length + 1, word1.Length + 1];

        for (int j = 1; j <= word1.Length; ++j)
        {
            db[0, j] = j;
        }

        for (int i = 1; i <= word2.Length; ++i)
        {
            db[i, 0] = i;
        }

        for (int i = 1; i <= word2.Length; ++i)
        {
            for (int j = 1; j <= word1.Length; ++j)
            {
                int transitionCost = word1[j - 1] == word2[i - 1] ? 0 : 1;

                db[i, j] = Math.Min(db[i - 1, j] + 1, Math.Min(db[i, j - 1] + 1, db[i - 1, j - 1] + transitionCost));
            }
        }

        return db[word2.Length, word1.Length];
    }
}