public class Solution {
    public int LargestSumAfterKNegations(int[] nums, int k) {
        Array.Sort(nums);

        var i = 0;

        while (i < nums.Length && k > 0 && nums[i] < 0)
        {
            nums[i] = -1 * nums[i];
            i++;
            k--;
        }

        if (i == nums.Length)
        {
            i--;
        }

        if (i > 0 && nums[i] > nums[i - 1])
        {
            i--;
        }

        while (i < nums.Length && k > 0)
        {
            nums[i] = -1 * nums[i];
            k--;
        }

        return nums.Sum();
    }
}