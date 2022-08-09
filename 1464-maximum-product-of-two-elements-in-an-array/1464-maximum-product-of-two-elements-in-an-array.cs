public class Solution {
    public int MaxProduct(int[] nums) {
        Array.Sort(nums);
        return (nums[^1] - 1) * (nums[^2] - 1);
    }
}