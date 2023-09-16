class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        pq.push({0, 0, 0});
        dp[0][0] = 0;
        
        while (!pq.empty()) {
            auto [effort, i, j] = pq.top();
            pq.pop();
            
            if (i == n-1 && j == m-1) {
                return effort;
            }
            
            for (auto& direction : directions) {
                int ni = i + direction.first;
                int nj = j + direction.second;
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int newEffort = max(effort, abs(heights[i][j] - heights[ni][nj]));
                    
                    if (newEffort < dp[ni][nj]) {
                        dp[ni][nj] = newEffort;
                        pq.push({newEffort, ni, nj});
                    }
                }
            }
        }
        
        return -1; // Return -1 if no path is found (this should not happen in this problem)
    }
};
