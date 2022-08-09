public class Solution {
    public int MaximumProduct(int[] nums) {
        Array.Sort(nums);
        return Math.Max(nums[^1] * nums[^2] * nums[^3], nums[0] * nums[1] * nums[^1]);
    }
}