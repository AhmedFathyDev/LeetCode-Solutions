public class Solution {
    public int[] SortArrayByParity(int[] nums) {
        var j = 0;
        
        for (var i = 0; i < nums.Length; ++i)
        {
            if (nums[i] % 2 != 0) continue;
            
            (nums[i], nums[j]) = (nums[j], nums[i]);
            j++;
        }
        
        return nums;
    }
}