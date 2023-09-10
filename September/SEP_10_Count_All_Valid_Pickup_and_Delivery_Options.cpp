class Solution
{
    int mod = 1e9 + 7;

public:
    int countOrders(int n)
    {
        if (n == 1)
            return 1;
        long long result = 1;
        for (int i = 2; i <= n; i++)
        {
            int space = (i - 1) * 2 + 1;
            int currPossibilities = ((space * (space + 1)) % mod) / 2;
            result = (result % mod * currPossibilities % mod) % mod;
        }
        return result;
    }
};