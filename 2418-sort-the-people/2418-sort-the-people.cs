public class Solution
{
    class Pair : IComparable<Pair>
    {
        public Pair(string name, int height)
        {
            Name = name;
            Height = height;
        }

        public string Name { get; set; }
        public int Height { get; set; }

        public int CompareTo(Pair pair)
        {
            return pair.Height.CompareTo(Height);
        }
    }
    
    public string[] SortPeople(string[] names, int[] heights)
    {
        var pairs = new Pair[names.Length];

        for (var i = 0; i < names.Length; ++i)
        {
            pairs[i] = new Pair(names[i], heights[i]);
        }

        Array.Sort(pairs);

        var sortedNames = new string[names.Length];

        for (var i = 0; i < names.Length; ++i)
        {
            sortedNames[i] = pairs[i].Name;
        }

        return sortedNames;
    }
}