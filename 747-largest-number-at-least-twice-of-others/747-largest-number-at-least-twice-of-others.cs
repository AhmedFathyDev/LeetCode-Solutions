public class Solution {
    public int DominantIndex(int[] nums) {
        var indexOfMaxNum = 0;
        var maxNum = int.MinValue;
        var secondMaxNum = int.MinValue;

        for (var i = 0; i < nums.Length; ++i)
        {
            if (nums[i] > maxNum)
            {
                secondMaxNum = maxNum;
                maxNum = nums[i];
                indexOfMaxNum = i;
            }
            else if (nums[i] > secondMaxNum)
            {
                secondMaxNum = nums[i];
            }
        }

        return maxNum >= secondMaxNum * 2 ? indexOfMaxNum : -1;
    }
}