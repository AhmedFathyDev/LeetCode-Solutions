class Solution
{
public:
    int trap(vector<int> &height)
    {
        int water_units = 0;

        int i = 0;
        int j = height.size() - 1;

        int max_left = 0;
        int max_right = 0;

        while (i <= j)
            if (height[i] <= height[j])
            {
                if (height[i] >= max_left)
                    max_left = height[i];
                else
                    water_units += max_left - height[i];

                ++i;
            }
            else
            {
                if (height[j] >= max_right)
                    max_right = height[j];
                else
                    water_units += max_right - height[j];

                --j;
            }
        
        return water_units;
    }
};
