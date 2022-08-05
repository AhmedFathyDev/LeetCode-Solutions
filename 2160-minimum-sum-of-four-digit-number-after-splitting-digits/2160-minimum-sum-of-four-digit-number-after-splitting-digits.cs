public class Solution {
    public int MinimumSum(int num) {
        var digits = new[] { num % 10, (num / 10) % 10, (num / 100) % 10, (num / 1000) % 10 };

        Array.Sort(digits);

        var new1 = digits[0] * 10 + digits[2];
        var new2 = digits[1] * 10 + digits[3];
        
        return new1 + new2;
    }
}