class Solution {
    int lowerBound(vector<int> &arr, int target){
        int left = 0, right = arr.size()-1;
        int ans = arr.size();
        while(left <= right){
            int mid = (left + right)/2;

            if(arr[mid] >= target){
                ans = mid;
                right = mid-1;
            }
            else if(arr[mid] < target){
                left = mid+1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &arr, int target){
        int left = 0, right = arr.size()-1;
        int ans = arr.size();

        while(left <= right){
            int mid = (left + right)/2;
            if(arr[mid] > target){
                ans = mid;
                right = mid-1;
            }
            else if(arr[mid] <= target){
                left = mid+1;
            }
        }
        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.empty()) return {-1, -1};

        //Handling not found case
        int l = lowerBound(nums, target);
        if(l == nums.size() || nums[l] != target) return {-1, -1};

        int u = upperBound(nums, target);
        return {l, u-1};
    }
};