class Solution
{
public:
    int trap(vector<int> &height)
    {
        int water_units = 0;

        int i = 0;
        int j = height.size() - 1;

        int max_i = 0;
        int max_j = 0;

        while (i < j)
            if (height[i] <= height[j])
            {
                if (max_i <= height[i])
                    max_i = height[i];
                else
                    water_units += max_i - height[i];

                ++i;
            }
            else
            {
                if (max_j <= height[j])
                    max_j = height[j];
                else
                    water_units += max_j - height[j];

                --j;
            }

        return water_units;
    }
};
