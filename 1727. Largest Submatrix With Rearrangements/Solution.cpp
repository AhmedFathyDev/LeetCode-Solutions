#define MAX(X, Y) ((X) < (Y) ? (Y) : (X))

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int area = 0;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int row = 0; row < m; ++row)
        {
            for (int col = 0; col < n; ++col)
                if (matrix[row][col] && row > 0)
                    matrix[row][col] += matrix[row - 1][col];

            vector<int> sorted_row = matrix[row];

            sort(sorted_row.begin(), sorted_row.end(), greater<int>());

            for (int col = 0; col < n; ++col)
                area = MAX(area, sorted_row[col] * (col + 1));
        }

        return area;
    }
};
