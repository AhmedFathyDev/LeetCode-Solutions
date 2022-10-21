public class Solution
{
    public int[][] ReconstructQueue(int[][] people)
    {
        Array.Sort(people,
            (personX, personY) => personX[0] == personY[0] ? personX[1] - personY[1] : personY[0] - personX[0]);

        var ans = new List<int[]>();

        foreach (var person in people)
        {
            ans.Insert(person[1], person);
        }

        return ans.ToArray();
    }
}