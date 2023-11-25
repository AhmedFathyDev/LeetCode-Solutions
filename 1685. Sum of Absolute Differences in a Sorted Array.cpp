class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int nums_size = nums.size();
        vector<int> result(nums_size);

        for (int i = 0; i < nums_size; ++i)
            result[0] += nums[i] - nums[0];

        for (int i = 1; i < nums_size; ++i)
            result[i] = result[i - 1] + i * (nums[i] - nums[i - 1]) - (nums_size - i) * (nums[i] - nums[i - 1]);

        return result;
    }
};
