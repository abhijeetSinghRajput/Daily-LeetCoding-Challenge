class Solution
{
    vector<int> dp;
    int solve(vector<int> &nums, int target)
    {
        if (target == 0)
        {
            return dp[target] = 1;
        }
        if (target < 0)
        {
            return 0;
        }
        // applying dp
        if (dp[target] != -1)
        {
            return dp[target];
        }

        int combination = 0;
        for (auto num : nums)
        {
            combination += solve(nums, target - num);
        }
        return dp[target] = combination;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(target + 1, -1);
        return solve(nums, target);
    }
};