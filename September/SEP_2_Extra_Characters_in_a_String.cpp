class Solution
{
    static bool cmp(string &s1, string &s2)
    {
        return s1.size() > s2.size();
    }
    int extraChar(string &s, int i, auto &hashTable, auto &dp)
    {
        if (i >= s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int val = INT_MAX;

        for (auto word : hashTable[s[i]])
        {

            // is word length fit
            if (i + word.size() <= s.size())
            {

                // pick a word and start matching
                bool matched = true;
                int j = 0;
                while (j < word.size())
                {
                    if (word[j] != s[i + j])
                    {
                        matched = false;
                        break;
                    }
                    j++;
                }

                // INCLUDE THE WORD
                if (matched)
                {
                    val = min(val, extraChar(s, i + word.size(), hashTable, dp));
                }
            }
        }

        // EXCLUDE THE FIRST CHAR (assume as extra)
        val = min(val, extraChar(s, i + 1, hashTable, dp) + 1);
        return dp[i] = val;
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        // map the distionary for ease in accessing
        sort(dictionary.begin(), dictionary.end(), cmp);

        // longer word will come first. be greedy larger matching word is better than smaller one

        unordered_map<char, vector<string>> hashTable;
        for (auto str : dictionary)
        {
            hashTable[str[0]].push_back(str);
        }

        vector<int> dp(s.size() + 1, -1);
        return extraChar(s, 0, hashTable, dp);
    }
};