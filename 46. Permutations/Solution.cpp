bool vectorContains(const vector<int> &nums, const int target)
{
    for (int num : nums)
        if (num == target)
            return true;

    return false;
}

class Solution
{
private:
    void backtrack(vector<vector<int>> &possibleSubsets, vector<int> newSubsets, vector<int> nums)
    {
        if (newSubsets.size() == nums.size())
            possibleSubsets.push_back(newSubsets);
        else
            for (int i = 0; i < nums.size(); ++i)
            {
                if (vectorContains(newSubsets, nums[i]))
                    continue; // element already exists, skip

                newSubsets.push_back(nums[i]);
                backtrack(possibleSubsets, newSubsets, nums);
                newSubsets.pop_back();
            }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> possibleSubsets;
        backtrack(possibleSubsets, {}, nums);
        return possibleSubsets;
    }
};
