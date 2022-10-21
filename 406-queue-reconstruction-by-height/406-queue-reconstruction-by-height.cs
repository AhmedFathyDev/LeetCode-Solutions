public class Solution
{
    public int[][] ReconstructQueue(int[][] people)
    {
        Array.Sort(people, (x, y) => x[0] == y[0] ? x[1] - y[1] : y[0] - x[0]);

        var ans = new List<int[]>();

        foreach (var person in people)
        {
            ans.Insert(person[1], person);
        }

        return ans.ToArray();
    }
}