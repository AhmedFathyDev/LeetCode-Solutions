public class Solution {
    public IList<bool> CheckArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        var answers = new List<bool>();
        
        for (var i = 0; i < l.Length; ++i)
        {
            var arithmeticSequences = true;
            var arr = new int[r[i] - l[i] + 1];

            for (var j = l[i]; j <= r[i]; ++j)
            {
                arr[j - l[i]] = nums[j];
            }

            Array.Sort(arr);

            var consecutiveElementsDifference = arr[1] - arr[0];

            for (var j = 2; j < arr.Length; ++j)
            {
                if (arr[j] - arr[j - 1] == consecutiveElementsDifference) continue;
                
                arithmeticSequences = false;
                break;
            }
            
            answers.Add(arithmeticSequences);
        }

        return answers;
    }
}