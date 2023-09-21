class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;\
        double ans;
        int i, j;
        for(i = 0, j = 0; i < nums1.size() && j < nums2.size();){
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i++]);
            }
            else{
                merged.push_back(nums2[j++]);
            }
        }
        while(i < nums1.size()){
            merged.push_back(nums1[i++]);
        }
        while(j < nums2.size()){
            merged.push_back(nums2[j++]);
        }
        if(merged.size() % 2 == 0){
            int mid = merged.size()/2;
            return (merged[mid] + merged[mid-1]) / 2.0;
        }
        else
        return merged[merged.size()/2];
    }
};