public class Solution {
    public int ThirdMax(int[] nums) {
        var distinctNums = nums.Distinct().ToArray();
        Array.Sort(distinctNums);

        return distinctNums.Length > 2 ? distinctNums[^3] : distinctNums[^1];
    }
}