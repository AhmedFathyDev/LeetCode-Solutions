
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))

int minDistance(char *word1, char *word2)
{
    int word1_length = strlen(word1);
    int word2_length = strlen(word2);

    int **dp_talbe = malloc((word2_length + 1) * sizeof(int *));

    for (int i = 0; i <= word2_length; ++i)
    {
        dp_talbe[i] = malloc((word1_length + 1) * sizeof(int));
        dp_talbe[i][0] = i;
    }

    for (int j = 1; j <= word1_length; ++j)
    {
        dp_talbe[0][j] = j;
    }

    for (int i = 1; i <= word2_length; ++i)
    {
        for (int j = 1; j <= word1_length; ++j)
        {
            dp_talbe[i][j] = MIN(dp_talbe[i - 1][j] + 1, MIN(dp_talbe[i][j - 1] + 1, dp_talbe[i - 1][j - 1] + (word1[j - 1] == word2[i - 1] ? 0 : 1)));
        }
    }

    return dp_talbe[word2_length][word1_length];
}