public class Solution {
    public int MaxWidthOfVerticalArea(int[][] points) {
        var ys = new int[points.Length];

        for (var i = 0; i < points.Length; ++i)
        {
            ys[i] = points[i][0];
        }

        Array.Sort(ys);
        var widestVerticalArea = 0;
        
        for (var i = 1; i < ys.Length; ++i)
        {
            widestVerticalArea = Math.Max(widestVerticalArea, ys[i] - ys[i - 1]);
        }

        return widestVerticalArea;
    }
}