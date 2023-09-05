class Solution
{
    static bool cmp(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] < v2[1];
    }

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        if (pairs.size() == 0)
            return 0;

        sort(pairs.begin(), pairs.end(), cmp);

        vector<int> curr = pairs[0];
        int chain = 1;

        for (auto pair : pairs)
        {
            if (curr[1] < pair[0])
            {
                chain++;
                curr = pair;
            }
        }

        return chain;
    }
};