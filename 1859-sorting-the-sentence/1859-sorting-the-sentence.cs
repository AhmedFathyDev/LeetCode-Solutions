public class Solution {
    public string SortSentence(string s) {
        var words = s.Split();
        var sentence = new string[words.Length];

        foreach (var word in words)
        {
            sentence[Convert.ToInt32(word.Last().ToString()) - 1] = word.Remove(word.Length - 1);
        }

        return string.Join(' ', sentence);
    }
}