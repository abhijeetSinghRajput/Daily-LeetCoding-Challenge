class Solution {
    vector<int> dp;
    int solve(vector<int> &cost, int i){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(solve(cost, i+1), solve(cost, i+2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        // ---------------Time O(N)  space :O(N)---------------
        // dp.resize(cost.size()+1, -1);
        // return min(solve(cost, 0), solve(cost, 1));



        // ---------------Time O(N)  space :O(1)---------------
        if(cost.size() < 2) return 0;

        vector<int> dp(3);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i<cost.size(); i++){
            dp[2] = cost[i] + min(dp[1], dp[0]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return min(dp[0], dp[1]);
    }
};