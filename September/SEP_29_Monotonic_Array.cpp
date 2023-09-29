class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        stack<int> stack;
        int n = nums.size();

        //should be increasing
        if(nums[0] <= nums[n-1]){
            for(int i = 0; i<n-1; i++){
                if(nums[i] > nums[i+1])
                return false;
            }
        }
        //should be decreasing
        else{
            for(int i = 0; i<n-1; i++){
                if(nums[i] < nums[i+1])
                return false;
            }
        }
        return true;
    }
};