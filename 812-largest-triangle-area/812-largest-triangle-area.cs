public class Solution {
    public double LargestTriangleArea(int[][] points) {
        return points.Aggregate(0.0, (current2, i) =>
            points.Aggregate(current2, (current1, j) =>
                points.Aggregate(current1, (current, k) =>
                    Math.Max(current, 0.5 * Math.Abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]
                                                     - i[1] * j[0] - j[1] * k[0] - k[1] * i[0])))));
    }
}