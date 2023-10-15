class Solution {
    int n, mod = 1e9+7;
    int dp[501][501];
    int solve(int i, int steps){
        if(i < 0 || i >= n) return 0;//outbound handling

        if(steps == 0){
            if(i == 0) return 1;
            return 0;
        }
        
        //memoization
        if(dp[i][steps] != -1) return dp[i][steps];

        int ans = 0;
        ans = (ans + solve(i+1, steps-1)) % mod;//move left
        ans = (ans + solve(i-1, steps-1)) % mod;//move right
        ans = (ans + solve(i, steps-1)) % mod;//stay

        return dp[i][steps] = ans;
    }
public:
    int numWays(int steps, int arrLen) {
        this->n = arrLen;
        memset(dp, -1, sizeof(dp));
        return solve(0, steps);
    }
};