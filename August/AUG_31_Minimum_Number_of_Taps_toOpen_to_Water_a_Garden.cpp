class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> range(n + 1);
        for (int i = 0; i <= n; i++)
        {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            range[left] = max(range[left], right);
        }

        int maxend = 0, currend = 0, taps = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i > maxend)
                return -1;
            if (i > currend)
            {
                taps++;
                currend = maxend;
            }
            maxend = max(maxend, range[i]);
        }
        return taps;
    }
};