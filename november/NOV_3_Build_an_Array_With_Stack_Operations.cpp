class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        vector<string> stack;
        //   j
        // 1 2 3
        // i = 2
        for(int i = 1; i<=n && j < target.size(); i++){
            int curr = target[j];
            // cout<<curr<<" "<<i<<endl;
            stack.push_back("Push");
            if(curr == i)j++;
            else{
                stack.push_back("Pop");
            }
        }
        return stack;
    }
};