public class Solution {
    public int FindLHS(int[] nums) {
        var map = new Dictionary<int, int>();
        var maxHarmoniousSubsequenceLength = 0;
        
        foreach (var num in nums)
        {
            map[num] = map.GetValueOrDefault(num) + 1;

            if (map.ContainsKey(num + 1))
            {
                maxHarmoniousSubsequenceLength = Math.Max(maxHarmoniousSubsequenceLength, map[num] + map[num + 1]);
            }
            if (map.ContainsKey(num - 1))
            {
                maxHarmoniousSubsequenceLength = Math.Max(maxHarmoniousSubsequenceLength, map[num] + map[num - 1]);
            }
        }

        return maxHarmoniousSubsequenceLength;
    }
}