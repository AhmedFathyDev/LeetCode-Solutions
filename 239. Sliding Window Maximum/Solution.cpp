class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int nums_size = nums.size();

        vector<int> max_nums(nums_size - k + 1, 0);

        deque<int> dq;

        for (int i = 0, j = 0; i < nums_size; ++i)
        {
            while (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                max_nums[j++] = nums[dq.front()];
            }
        }

        return max_nums;
    }
};
