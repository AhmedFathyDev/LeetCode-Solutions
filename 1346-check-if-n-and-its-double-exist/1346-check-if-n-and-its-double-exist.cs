public class Solution {
    public bool CheckIfExist(int[] arr) {

        for (var i = 0; i < arr.Length; ++i)
        {
            for (var j = 0; j < arr.Length; ++j)
            {
                if (arr[i] * 2 == arr[j] && i != j)
                {
                    return true;
                }
            }
        }

        return false;
    }
}