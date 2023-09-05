class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        map<int, set<int>> hashTable;

        for (auto i : stones)
        {
            hashTable.insert({i, set<int>()});
        }
        // there is one way for starting
        hashTable[0].insert(1);
        for (int i = 0; i < stones.size(); i++)
        {
            int stone = stones[i];

            for (auto k : hashTable[stone])
            {
                // k jump laga ke next pe pahunche
                int next = stone + k;
                // if next stone exit
                if (hashTable.find(next) != hashTable.end())
                {
                    if (k - 1 > 0)
                    {
                        hashTable[next].insert(k - 1);
                    }
                    hashTable[next].insert(k + 1);
                    hashTable[next].insert(k);
                }
            }
        }

        //{stones, set()} rbegin() last index
        // second -> set{k1,k2,k3}
        return !hashTable.rbegin()->second.empty();
    }
};