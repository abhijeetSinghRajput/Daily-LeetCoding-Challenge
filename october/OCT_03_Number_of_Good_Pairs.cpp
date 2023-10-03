class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        //freq           pairs
        //1. 1           0
        //2. 1,1         1
        //3. 1,1,1       2+1
        //4. 1,1,1,1     3+2+1  
        //5. 1,1,1,1,1   4+3+2+1  

        //(freq-1) * (freq-1+1)/2

        int sum = 0;
        unordered_map<int, int> freq;
        for(auto num : nums){
            freq[num]++;
        }
        for(auto p : freq){
            sum += ((p.second-1) * (p.second))/2;
        }
        return sum;
    }
};