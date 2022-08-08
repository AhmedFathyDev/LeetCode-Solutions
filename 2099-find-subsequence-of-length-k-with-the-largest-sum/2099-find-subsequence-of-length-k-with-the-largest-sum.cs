public class Solution {
    public int[] MaxSubsequence(int[] nums, int k) {
        var sortedNums = new int[nums.Length];
        
        Array.Copy(nums, 0, sortedNums, 0, nums.Length);
        Array.Sort(sortedNums);

        var maxNums = new List<int>();
        
        for (var i = sortedNums.Length - k; i < sortedNums.Length; ++i)
        {
            maxNums.Add(sortedNums[i]);
        }
        
        var subNums = new List<int>();

        foreach (var num in nums)
        {
            if (maxNums.All(maxNum => num != maxNum)) continue;
            subNums.Add(num);
            maxNums.Remove(num);
        }

        return subNums.ToArray();
    }
}