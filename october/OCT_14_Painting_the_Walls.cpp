class Solution {
    vector<vector<int>> dp;
    int solve(int i, int walls, vector<int> &time, vector<int> &cost){
        if(walls <= 0) return 0;//no walls remains to paint
        if(i >= time.size()) return 1e9;


        if(dp[i][walls] != -1) return dp[i][walls];
        
        //***"walls-1", one wall painted
        //****while taking time[i] to paint meanwhile
        // freePainter will paint time[i] no of walls
        int painted = cost[i] + solve(i+1, walls-1-time[i], time, cost);
        //skip
        int skip = solve(i+1, walls, time, cost);

        return dp[i][walls] = min(painted, skip);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(0, n, time, cost);
    }
};