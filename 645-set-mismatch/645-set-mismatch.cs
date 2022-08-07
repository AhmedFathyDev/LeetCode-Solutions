public class Solution {
    public int[] FindErrorNums(int[] nums) {
        var freqNums = new int[10001];

        var numMissed = 0;
        var numOccuredTwice = 0;

        foreach (var num in nums)
        {
            if (freqNums[num] == 1)
            {
                numOccuredTwice = num;
            }

            freqNums[num]++;
        }

        for (var i = 1; i <= nums.Length; ++i)
        {
            if (freqNums[i] == 0)
            {
                numMissed = i;
            }
        }

        return new int[] { numOccuredTwice, numMissed };
    }
}