public class Solution {
    public int MaxCoins(int[] piles) {
        var coins = 0;
        Array.Sort(piles);

        for (var i = piles.Length - 1; i > piles.Length / 3; i -= 2)
        {
            coins += piles[i - 1];
        }

        return coins;
    }
}