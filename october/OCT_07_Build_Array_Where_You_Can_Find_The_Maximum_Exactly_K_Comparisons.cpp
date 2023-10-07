class Solution {
    int N, M, K, mod = 1e9+7;
    int dp[51][101][51];
    int solve(int currIndex,int maximum,int cost){
        if(currIndex == N){
            if(cost == K){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[currIndex][maximum][cost] != -1)
        return dp[currIndex][maximum][cost];

        int result = 0;
        for(int i = 1; i<=M; i++){
            if(i > maximum){
                result = (result + solve(currIndex + 1, i, cost+1)) % mod;
            }
            else{
                result = (result + solve(currIndex + 1, maximum, cost)) % mod;
            }
        }
        return dp[currIndex][maximum][cost] = result;
    }
public:
    int numOfArrays(int n, int m, int k) {
        this->N = n;
        this->M = m;
        this->K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};