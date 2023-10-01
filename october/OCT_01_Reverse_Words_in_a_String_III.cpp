class Solution {
public:
    string reverseWords(string s) {
        int i, j;
        for( i = 0, j = 0; i<s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin() + j, s.begin() + i);
                j = i+1;
            }
        }
        reverse(s.begin() + j, s.end());
        return s;
    }
};