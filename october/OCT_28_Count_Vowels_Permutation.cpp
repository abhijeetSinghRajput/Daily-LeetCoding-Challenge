struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Assuming sizeof(size_t) == 2 * sizeof(unsigned int)
        return (h1 << sizeof(std::size_t) / 2) ^ h2;
    }
};
class Solution {
    int N, mod = 1e9+7;
    string vowels = "aeiou";
    unordered_map<pair<char, int>, int, pair_hash> dp;

    long long solve(char endsWith, int n){
        if(n == N)
            return 1;
        if(dp.find({endsWith, n}) != dp.end())
            return dp[{endsWith, n}];

        long long count = 0;

        if(endsWith == 'a'){
            count = (count + solve('e', n+1))%mod;
        }
        else if(endsWith =='e'){
            count = (count + solve('a', n+1))%mod;
            count = (count + solve('i', n+1))%mod;
        }
        else if(endsWith == 'i'){
            for(auto vowel : vowels){
                if(vowel != 'i')
                count = (count + solve(vowel, n+1))%mod;
            }
        }
        else if(endsWith == 'o'){
            count = (count + solve('i', n+1))%mod;
            count = (count + solve('u', n+1))%mod;
        }
        else if(endsWith == 'u'){
            count = (count + solve('a', n+1))%mod;
        }
        return dp[{endsWith,n}] = count;
    }

public:

    int countVowelPermutation(int n) {
        this->N = n;
        long long count = 0;
        for(int i = 0; i<vowels.size(); i++){
            count = (count + solve(vowels[i],1)) % mod;
        }
        return count;
    }
};