public class Solution {
    public int PartitionArray(int[] nums, int k) {
        Array.Sort(nums);

        var j = 0;
        var minimumSubsequences = 0;

        for (var i = 1; i < nums.Length; ++i)
        {
            if (nums[i] - nums[j] > k)
            {
                j = i;
                minimumSubsequences++;
            }
        }

        return minimumSubsequences + 1;
    }
}