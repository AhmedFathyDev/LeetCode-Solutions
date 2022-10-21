public class Solution
{
    public int LargestPerimeter(int[] nums)
    {
        Array.Sort(nums);
        Array.Reverse(nums);

        var largestPerimeter = 0;

        for (var i = 0; i < nums.Length - 2; ++i)
        {
            if (nums[i] < nums[i + 1] + nums[i + 2])
            {
                largestPerimeter = Math.Max(largestPerimeter, nums[i] + nums[i + 1] + nums[i + 2]);
            }
        }

        return largestPerimeter;
    }
}