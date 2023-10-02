<<<<<<< HEAD
class Solution
{
    int count(int n)
    {
        int i = 0;
        while (n)
        {
            n &= (n - 1);
            i++;
        }
        return i;
    }

public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            ans[i] = count(i);
        }
        return ans;
    }
};
=======
class Solution
{
    int count(int n)
    {
        int i = 0;
        while (n)
        {
            n &= (n - 1);
            i++;
        }
        return i;
    }

public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            ans[i] = count(i);
        }
        return ans;
    }
};
>>>>>>> 20b74905543e6f2c1e9f6645cdcc1758f7124c27
