class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> map;
        vector<vector<int>> ans;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            // group became full
            int size = groupSizes[i];
            map[size].push_back(i);

            if (map[size].size() == size)
            {
                ans.push_back(map[size]);
                map[size].clear();
            }
        }
        return ans;
    }
};