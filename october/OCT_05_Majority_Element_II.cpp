class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();
        //complexity:
        //time : O(N)
        //space : O(N)

        // unordered_map<int, int> freq;
        // for(auto num : nums){
        //     freq[num]++;
        // }

        // for(auto i : freq){
        //     if(i.second > nums.size()/3){
        //         ans.push_back(i.first);
        //     }
        // }




        //complexity:
        //time : O(logN)
        //space : O(1)

        // sort(nums.begin(), nums.end());
        // int count = 0;

        // for(int i = 0; i<n; i++){
        //     if(i > 0 && nums[i-1] != nums[i]){
        //         if(count > n/3)
        //         ans.push_back(nums[i-1]);
        //         count = 0;
        //     }
        //     count++;
        // }
        // if(count > n/3){
        //     ans.push_back(nums[n-1]);
        // }


        //there will be at most two majority element in the ans
        int element1 = INT_MIN, element2 = INT_MIN;
        int count1 = 0, count2 = 0;

        for(auto num : nums){
            if(count1 == 0 && num != element2){
                element1 = num;
                count1 = 1;
            }
            else if(count2 == 0 && num != element1){
                element2 = num;
                count2 = 1;
            }
            else if(num == element1){
                count1++;
            }
            else if(num == element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        int majority = n/3;
        count1 = count2 = 0;
        
        for(auto num : nums){
            if(element1 == num)
            count1++;
        }

        for(auto num : nums){
            if(element2 == num)
            count2++;
        }

        if(count1 > majority) ans.push_back(element1);
        if(count2 > majority) ans.push_back(element2);

        return ans;
    }
};