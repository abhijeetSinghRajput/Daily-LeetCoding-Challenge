class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;

        if(target == 0)
        return nums.size();

        //find longest subArray with target sum
        int i = 0, j = 0, maxSize = 0, sum = 0;
        while(j < nums.size()){
            sum += nums[j];
            while(sum > target && i < j){
                sum -= nums[i++];
            }
            if(sum == target){
                int subArrSize = (j - i) + 1;
                cout<<subArrSize<<endl;
                maxSize = max(maxSize, subArrSize);
            }
            j++;
        }
        if(maxSize == 0)return -1;
        return nums.size() - maxSize;
    }
};