class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;

        size_t nums_size = nums.size();

        for (size_t i = 0; i < nums_size; ++i)
        {
            size_t j = i + 1;
            size_t k = nums_size - 1;

            while (j < k)
                if (nums[i] + nums[j] + nums[k] < 0)
                    ++j;
                else if (nums[i] + nums[j] + nums[k] == 0 && i != j && i != k)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};

                    triplets.push_back(triplet);

                    while (j < k && nums[j] == triplet[1])
                        ++j;

                    while (j < k && nums[k] == triplet[2])
                        --k;
                }
                else
                    --k;

            while (i + 1 < nums_size && nums[i + 1] == nums[i])
                ++i;
        }

        return triplets;
    }
};
