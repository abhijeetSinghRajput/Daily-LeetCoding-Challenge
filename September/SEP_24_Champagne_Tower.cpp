class Solution {
    vector<vector<double>> dp;
    double solve(int poured, int i, int j){
        if(i < 0 || j < 0 || i < j) return 0;
        if(i == 0) return poured;
        if(dp[i][j] != -1) return dp[i][j];

        //-1 represent 1 cup full hone ke bad kitna mila
        //2.0 represent jo mila uko 2 hisso me bant liya
        double left = (solve(poured, i-1, j-1) - 1) / 2.0;
        double right = (solve(poured, i-1, j) - 1) / 2.0;

        if(left < 0) left = 0;
        if(right < 0) right = 0;

        return dp[i][j] = (left + right);
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        dp.resize(query_row + 1, vector<double>(query_glass + 1, -1));
        //1 se jyada hua to floor pe gir jayega
        return min(1.0, solve(poured, query_row, query_glass));
    }
};