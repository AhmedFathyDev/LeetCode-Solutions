class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int nums_size = nums.size();

        for (int num : nums)
        {
            int i = abs(num);

            if (nums[i] < 0)
                return i;

            nums[i] = -nums[i];
        }

        return 0;
    }
};
