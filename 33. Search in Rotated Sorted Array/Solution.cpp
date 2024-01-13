
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int nums_size = nums.size();
        int left = 0, right = nums_size - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        int rotated = left;

        left = 0, right = nums_size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int real_mid = (rotated + mid) % nums_size;

            if (nums[real_mid] == target)
                return real_mid;

            if (nums[real_mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};
