/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int findPeak(MountainArray &mountainArr){
    int left = 0;
    int right = mountainArr.length()-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return left;
    }

    int binarySearch(MountainArray &mountainArr, int left, int right, int target){
        while(left <= right){
            int mid = left + (right - left)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return -1;
    }
    int reverseBinarySearch(MountainArray &mountainArr, int left, int right, int target){
        while(left <= right){
            int mid = left + (right - left)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int valueAt = binarySearch(mountainArr, 0, peak, target);
        if(valueAt != -1)
        return valueAt;

        return reverseBinarySearch(mountainArr, peak+1, mountainArr.length()-1, target);
    }
};