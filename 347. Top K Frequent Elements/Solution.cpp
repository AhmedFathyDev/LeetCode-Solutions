class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;

        for (int num : nums)
            mp[num]++;

        vector<pair<int, int>> mp_vector;

        for (pair<int, int> num : mp)
            mp_vector.push_back({num.second, num.first});

        sort(mp_vector.begin(), mp_vector.end(), greater<pair<int, int>>());

        for (int i = 0; i < mp_vector.size(); ++i)
            cout << mp_vector[i].first << " " << mp_vector[i].second;

        vector<int> ans(k);

        for (int i = 0; i < k; ++i)
            ans[i] = mp_vector[i].second;

        return ans;
    }
};
