public class Solution {
    public int[] DeckRevealedIncreasing(int[] deck) {
        var answerOrder = new int[deck.Length];
        var indices = new Queue<int>();

        for (var i = 0; i < deck.Length; ++i)
        {
            indices.Enqueue(i);
        }

        Array.Sort(deck);

        foreach (var card in deck)
        {
            answerOrder[indices.Dequeue()] = card;

            if (indices.Count <= 0) break;

            indices.Enqueue(indices.Dequeue());
        }

        return answerOrder;
    }
}