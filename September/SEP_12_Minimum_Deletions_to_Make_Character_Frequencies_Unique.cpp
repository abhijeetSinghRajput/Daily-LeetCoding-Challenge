class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> map;
        unordered_set<int> set;
        for (auto c : s)
        {
            map[c]++;
        }
        int deletes = 0;
        for (auto &pair : map)
        {
            while (pair.second != 0 && set.find(pair.second) != set.end())
            {
                pair.second--;
                deletes++;
            }
            if (pair.second != 0)
            {
                set.insert(pair.second);
            }
        }
        return deletes;
    }
};