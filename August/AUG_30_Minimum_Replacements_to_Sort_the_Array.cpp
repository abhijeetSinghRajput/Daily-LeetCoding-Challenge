class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long Total_Operation = 0;
        
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                int parts = nums[i] / nums[i+1];
                if(nums[i] % nums[i+1] != 0)
                    parts++;

                int operation = parts - 1;
                Total_Operation += operation;

                nums[i] = nums[i] / parts;
            }
        }

        return Total_Operation;
    }
};