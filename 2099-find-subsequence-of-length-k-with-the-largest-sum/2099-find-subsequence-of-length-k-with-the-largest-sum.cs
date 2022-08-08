public class Solution {
    public int[] MaxSubsequence(int[] nums, int k) {
                var sortedNums = new int[nums.Length];
        Array.Copy(nums, 0, sortedNums, 0, nums.Length);
        Array.Sort(sortedNums);
        Array.Reverse(sortedNums);

        var maxNums = new List<int>();
        var subNums = new List<int>();
        
        for (var i = 0; i < k; ++i)
        {
            maxNums.Add(sortedNums[i]);
        }

        foreach (var num in nums)
        {
            if (maxNums.Any(maxNum => num == maxNum))
            {
                subNums.Add(num);
                maxNums.Remove(num);
            }
        }

        return subNums.ToArray();
    }
}