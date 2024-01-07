class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix[0].size();
        int n = matrix.size();

        int fir = 0;
        int las = m * n - 1;

        while (fir <= las)
        {
            int mid = fir + (las - fir) / 2;

            if (matrix[mid / m][mid % m] < target)
                fir = mid + 1;
            else if (matrix[mid / m][mid % m] == target)
                return true;
            else
                las = mid - 1;
        }

        return false;
    }
};
