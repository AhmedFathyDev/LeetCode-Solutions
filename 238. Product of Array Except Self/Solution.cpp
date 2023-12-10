class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int product = 1;
        int zeros = 0;
        int nums_size = nums.size();

        for (int i = 0; i < nums_size; ++i)
            if (nums[i])
                product *= nums[i];
            else
                zeros++;

        for (int i = 0; i < nums_size; ++i)
            if (!zeros)
                nums[i] = product / nums[i];
            else if (zeros == 1)
                if (nums[i])
                    nums[i] = 0;
                else
                    nums[i] = product;
            else
                nums[i] = 0;

        return nums;
    }
};
