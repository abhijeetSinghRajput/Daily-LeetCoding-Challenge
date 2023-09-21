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



//constant space solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, k = 0;
        double curr = 0, prev;

        while(i < n && j < m && k <= (m+n)/2){
            if(nums1[i] < nums2[j]){
                prev = curr;
                curr = nums1[i++];
            }
            else{
                prev = curr;
                curr = nums2[j++];
            }
            k++;
        }

        while(i < n && k <= (m+n)/2){
            prev = curr;
            curr = nums1[i++];
            k++;
        }
        while(j < m && k <= (m+n)/2){
            prev = curr;
            curr = nums2[j++];
            k++;
        }

        if((m+n) % 2 == 0){
            return (prev + curr) / 2.0;
        }
        else{
            return curr;
        }
    }
};