public class Solution {
    public int MinPairSum(int[] nums) {
        Array.Sort(nums);

        var maxPairSum = 0;

        for (var i = 0; i < nums.Length / 2; ++i)
        {
            maxPairSum = Math.Max(maxPairSum, nums[i] + nums[^(i + 1)]);
        }

        return maxPairSum;
    }
}