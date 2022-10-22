public class Solution
{
    public int[] CountPoints(int[][] points, int[][] queries)
    {
        int Distance(int x1, int y1, int x2, int y2)
        {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        }

        var answer = new int[queries.Length];

        for (var i = 0; i < queries.Length; ++i)
        {
            answer[i] = points.Count(point => Distance(queries[i][0], queries[i][1], point[0], point[1]) <= queries[i][2] * queries[i][2]);
        }

        return answer;
    }
}