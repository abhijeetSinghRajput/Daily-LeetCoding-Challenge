class Solution
{
    void display(auto map)
    {
        for (auto i : map)
            cout << i.first << " " << i.second << endl;
    }

public:
    string reorganizeString(string s)
    {
        string ans(s.size(), ' ');

        unordered_map<char, int> map;
        // step 1 count the frequency
        for (auto i : s)
        {
            map[i]++;
        }

        // step 2 find the element with max frequency
        pair<char, int> maxFreq; //{char, freq}
        maxFreq.second = 0;
        for (auto i : map)
        {
            if (maxFreq.second < i.second)
                maxFreq = i;
        }

        // edge case
        if (maxFreq.second > (s.size() + 1) / 2)
            return "";

        // step 3 evenly distrubute that element ex:- at (0,2,4,...)
        int i = 0;
        while (map[maxFreq.first]-- && i < ans.size())
        {
            ans[i] = maxFreq.first;
            i += 2;
        }
        display(map);
        // step4 put rest element remain in the map
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            while (it->second > 0)
            {
                if (i >= ans.size())
                    i = 1;
                ans[i] = it->first;
                it->second--;
                i += 2;
            }
        }
        // cout<<maxFreq.first<<" "<<maxFreq.second;
        return ans;
    }
};