class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;

        int i = 0;
        int j = 0;

        int prices_size = prices.size();

        while (++j < prices_size)
            if (prices[i] < prices[j])
                max_profit = max(max_profit, prices[j] - prices[i]);
            else
                i = j;

        return max_profit;
    }
};
