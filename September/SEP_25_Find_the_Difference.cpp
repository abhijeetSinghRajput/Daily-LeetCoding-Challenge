class Solution {
public:
    char findTheDifference(string s, string t) {
        char x = s[0];
        for(int i = 1; i<s.size(); i++){
            x ^= s[i];
        }
        for(char c : t){
            x ^= c;
        }
        return x;
    }
};