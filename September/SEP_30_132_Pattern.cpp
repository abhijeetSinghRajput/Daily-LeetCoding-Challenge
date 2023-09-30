class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        //time complexity N³

        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         for(int k = j+1; k< n; k++){
        //             if(nums[i] < nums[k] && nums[k] < nums[j])
        //             return true;
        //         }
        //     }
        // }return false;




        // time complexity N²

        // int preMin[n];
        // preMin[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] < preMin[i-1]){
        //         preMin[i] = nums[i];
        //     }
        //     else{
        //         preMin[i] = preMin[i-1];
        //     }
        // }

        // for(int i = 0; i<n; i++){
        //     if(preMin[i] < nums[i]){
        //         //looking ahead
        //         for(int j = i+1; j<n; j++){
        //             if(preMin[i] < nums[j] && nums[j] < nums[i])
        //             return true;
        //         }
        //     }
        // }
        // return false;



        // time complexity N¹
        //num1 < num3 < num2
        int num3 = INT_MIN;
        stack<int> stack;

        for(int i = nums.size()-1 ; i>= 0; i--){
            if(nums[i] < num3)
            return true;

            while(!stack.empty() && stack.top() < nums[i]){
                num3 = stack.top();
                stack.pop();
            }
            stack.push(nums[i]);
        }
        return false;
    }
};