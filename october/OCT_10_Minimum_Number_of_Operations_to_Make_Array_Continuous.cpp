class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // for(int i = 0; i<n; i++){
        //     int mn = nums[i];
        //     int mx = mn + n-1;
        //     int operation = 0;

        //     unordered_set<int> set;
        //     for(auto num : nums){

        //         if(num < mn || num > mx || set.find(num) != set.end()){
        //             operation++;
        //         }
        //         set.insert(num);
        //     }
        //     ans = min(ans, operation);
        // }



        //sort ans remove duplication
        set<int> s(nums.begin(), nums.end());
        vector<int> arr(s.begin(), s.end());
        
        for(int i = 0; i<arr.size(); i++){
            int mx = arr[i] + n-1;
            int j = upper_bound(arr.begin(), arr.end(), mx) - arr.begin();
            
            int inRange = j - i;
            int outRange = n - inRange;

            ans = min(ans, outRange);
        }
        
        return ans;
    }
};