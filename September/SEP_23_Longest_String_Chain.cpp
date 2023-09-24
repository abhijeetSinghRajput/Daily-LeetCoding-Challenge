class Solution {
    int n;
    vector<vector<int>> dp;
    bool isPredecessor(string &word1, string &word2){
        int M = word1.size();
        int N = word2.size();

        if(N - M != 1) return false;

        int i = 0, j = 0;
        while(i < M && j < N){
            if(word1[i] == word2[j]){
                i++;
            }
            j++;
        }
        return i == M;
    }

    static bool cmp(string &word1, string &word2){
        return word1.size() < word2.size();
    }

    int lis(int prev, int curr, vector<string> &words){
        if(curr == n) return 0;
        if(prev != -1 && dp[prev][curr] != -1)
        return dp[prev][curr];

        int take = 0;
        if(prev == -1 || isPredecessor(words[prev], words[curr])){
            take = 1 + lis(curr, curr+1, words);
        }
        int notTake = lis(prev, curr+1, words);

        if(prev != -1){
            dp[prev][curr] = max(take, notTake);
        }
        return max(take, notTake);
    }
public:
    int longestStrChain(vector<string>& words) {
        dp.resize(1001, vector<int>(1001, -1));
        n = words.size();
        sort(words.begin(), words.end(), cmp);

        return lis(-1, 0, words);
    }
};