#include <bits/stdc++.h>

#define MAX(X, Y) ((X) < (Y) ? (Y) : (X))
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        if (nums1_size > nums2_size)
            return findMedianSortedArrays(nums2, nums1);

        int merged_nums_size = nums1_size + nums2_size;
        int median = merged_nums_size / 2;

        int nums1_left = 0;
        int nums1_right = nums1_size - 1;

        while (true)
        {
            int nums1_mid = MIN(nums1_right, nums1_left + (nums1_right - nums1_left) / 2);
            int nums2_mid = median - 1 - nums1_mid - 1;

            int nums1_mid_left = nums1_mid >= 0 ? nums1[nums1_mid] : INT_MIN;
            int nums1_mid_right = (nums1_mid + 1) < nums1_size ? nums1[nums1_mid + 1] : INT_MAX;

            int nums2_mid_left = nums2_mid >= 0 ? nums2[nums2_mid] : INT_MIN;
            int nums2_mid_right = (nums2_mid + 1) < nums2_size ? nums2[nums2_mid + 1] : INT_MAX;

            if (nums1_mid_left <= nums2_mid_right && nums2_mid_left <= nums1_mid_right)
            {
                if (merged_nums_size & 1)
                    return (double)MIN(nums1_mid_right, nums2_mid_right);

                return ((double)MAX(nums1_mid_left, nums2_mid_left) + (double)MIN(nums1_mid_right, nums2_mid_right)) / 2.0;
            }

            if (nums1_mid_left > nums2_mid_right)
                nums1_right = nums1_mid - 1;
            else
                nums1_left = nums1_mid + 1;
        }

        return 0.0;
    }
};
