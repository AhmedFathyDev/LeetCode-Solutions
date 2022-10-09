public class Solution {
    public string ReverseStr(string s, int k) {
        void Reverse(IList<char> chars, int start, int end)
        {
            while(start < end)
            {
                (chars[start], chars[end]) = (chars[end], chars[start]);

                start++;
                end--;
            }
        }
        
        var charsOfS = s.ToCharArray();

        for (var i = 0; i < charsOfS.Length; i += 2 * k)
        {
            Reverse(charsOfS, i, Math.Min(i + k - 1, charsOfS.Length - 1));
        }

        return new string(charsOfS);
    }
}