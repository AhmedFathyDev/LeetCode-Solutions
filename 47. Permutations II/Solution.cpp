class Solution
{
private:
    void backtrack(vector<vector<int>> &possibleSubsets, vector<int> newSubsets, vector<int> nums, vector<bool> used)
    {
        if (newSubsets.size() == nums.size())
            possibleSubsets.push_back(newSubsets);
        else
            for (int i = 0; i < nums.size(); ++i)
            {
                if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;

                used[i] = true;
                newSubsets.push_back(nums[i]);
                backtrack(possibleSubsets, newSubsets, nums, used);
                used[i] = false;
                newSubsets.pop_back();
            }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> possibleSubsets;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(possibleSubsets, {}, nums, used);
        return possibleSubsets;
    }
};
