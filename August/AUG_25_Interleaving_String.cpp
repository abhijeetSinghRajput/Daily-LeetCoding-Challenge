class Solution
{
    bool recursion(const string &s1, const string &s2, const string &s3, int i, int j, int k, auto &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        // base case
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return true;

        bool x = false, y = false;
        if (i < s1.size() && s1[i] == s3[k])
        {
            x = recursion(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        if (j < s2.size() && s2[j] == s3[k])
        {
            y = recursion(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        return dp[i][j] = x || y;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return recursion(s1, s2, s3, 0, 0, 0, dp);
    }
};