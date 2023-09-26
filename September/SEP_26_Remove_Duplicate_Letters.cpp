class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stack;
        vector<int> lastIndexOf(26, -1);
        for(int i = 0; i<s.size(); i++){
            lastIndexOf[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        for(int i = 0; i<s.size(); i++){
            //lastIndexOf[stack.top()]
            //agar tum abad me aa hi skte ho to fir niklo 
            if(visited[s[i] - 'a']) continue;
            while(!stack.empty() && stack.top() > s[i] && lastIndexOf[stack.top()-'a'] > i){
                visited[stack.top()-'a'] = false;
                stack.pop();
            }
            stack.push(s[i]);
            visited[s[i] - 'a'] = true;
        }

        string ans;
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};