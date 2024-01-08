#define MAX(X, Y) ((X) < (Y) ? (Y) : (X))
#define CEIL(X, Y) (((X) + (Y)-1) / (Y))

class Solution
{
private:
    bool is_valid_speed(vector<int> &piles, int n, int h, int k)
    {
        long long sum = 0;

        for (int i = 0; i < n; ++i)
            sum += CEIL(piles[i], k);

        return sum <= h;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int k = 1;

        int min_speed = 1;
        int max_speed = 1;

        int n = piles.size();

        for (int i = 0; i < n; ++i)
            max_speed = MAX(max_speed, piles[i]);

        while (min_speed <= max_speed)
        {
            int mid_speed = min_speed + (max_speed - min_speed) / 2;

            if (is_valid_speed(piles, n, h, mid_speed))
            {
                k = mid_speed;
                max_speed = mid_speed - 1;
            }
            else
                min_speed = mid_speed + 1;
        }

        return k;
    }
};
