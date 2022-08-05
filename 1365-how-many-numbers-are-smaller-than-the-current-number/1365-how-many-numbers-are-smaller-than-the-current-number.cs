public class Solution {
    public int[] SmallerNumbersThanCurrent(int[] nums) {
        var freq = new int[101];

        foreach (var num in nums)
        {
            freq[num]++;
        }

        for (var i = 1; i < 101; ++i)
        {
            freq[i] += freq[i - 1];
        }

        for (var i = 0; i < nums.Length; ++i)
        {
            if (nums[i] == 0) continue;
            
            nums[i] = freq[nums[i] - 1];
        }

        return nums;
    }
}