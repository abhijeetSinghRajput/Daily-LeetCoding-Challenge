class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;

        //Time Complexity : people.size * flower
        // for(auto i : people){
        //     int count = 0;
        //     for(auto flower : flowers){
        //         if(flower[0] <= i && i <= flower[1])
        //         count++;
        //     }
        //     ans.push_back(count);
        // }

        int n = flowers.size();
        vector<int> startTime(n), endTime(n);
        for(int i = 0; i<n; i++){
            startTime[i] = flowers[i][0];
            endTime[i] = flowers[i][1];
        }
        
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        for(auto& p : people){
            int i = upper_bound(startTime.begin(), startTime.end(), p) - startTime.begin();
            int j = lower_bound(endTime.begin(), endTime.end(), p) - endTime.begin();

            ans.push_back(i-j);
        }
        return ans;
    }
};