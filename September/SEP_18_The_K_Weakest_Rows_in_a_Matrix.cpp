class Solution {
public:
    vector<pair<int,int>> arr;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for(int i = 0; i<mat.size(); i++){
            int sum = 0;
            for(int j = 0; j<mat[0].size(); j++){
                sum += mat[i][j];
            }
            arr.push_back({sum, i});
        }
        sort(arr.begin(), arr.end());
        for(auto i : arr){
            cout<<i.first<<" "<<i.second<<endl;
        }
        vector<int> vec;
        for(int i = 0; i<k; i++){
            vec.push_back(arr[i].second);
        }
        return vec;
    }
};