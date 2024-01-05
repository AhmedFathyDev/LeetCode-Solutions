class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int fir = 0;
        int las = nums.size() - 1;

        while (fir <= las)
        {
            int mid = fir + (las - fir) / 2;

            if (nums[mid] < target)
                fir = mid + 1;
            else if (nums[mid] == target)
                return mid;
            else
                las = mid - 1;
        }

        return -1;
    }
};
