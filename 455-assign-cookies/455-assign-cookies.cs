public class Solution {
    public int FindContentChildren(int[] g, int[] s) {
        Array.Sort(g);
        Array.Sort(s);

        var cookieIndex = 0;
        var childGreedIndex = 0;
        var contentChildren = 0;

        while (cookieIndex < s.Length && childGreedIndex < g.Length)
        {
            if (s[cookieIndex] >= g[childGreedIndex])
            {
                cookieIndex++;
                childGreedIndex++;
                contentChildren++;
            }
            else
            {
                cookieIndex++;
            }
        }

        return contentChildren;
    }
}