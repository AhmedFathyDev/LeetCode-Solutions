public class Solution {
    public int MaxProductDifference(int[] nums) {
        Array.Sort(nums);
        return (nums[^1] * nums[^2]) - (nums[0] * nums[1]);
    }
}