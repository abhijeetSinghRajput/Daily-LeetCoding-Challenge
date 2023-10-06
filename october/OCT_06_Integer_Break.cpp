class Solution {
    vector<int> dp;
    int solve(int n){
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        int result = INT_MIN;
        for(int i = 1; i<n; i++){
            int prod = i * max(n-i, solve(n-i));
            result = max(result, prod);
        }

        return dp[n] = result;
    }
public:
    //Time complexity: O(N)
    int integerBreak(int n) {
        dp.resize(n+1, -1);
        return solve(n);
    }
};