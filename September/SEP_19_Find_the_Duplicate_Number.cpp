class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Intution use the two pointer approch as you used in Linked List while 
        //detecting loop position

        //detect loop
        int slow = -1, fast = 0;
        while(slow != fast){
            if(slow == -1) slow++;
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }


        //find loop size
        slow = nums[slow];
        int loopSize = 1;
        while(slow != fast){
            slow = nums[slow];
            loopSize++;
        }

        //move one pointer by loopSize
        fast = nums[0];
        slow = nums[0];
        while(loopSize--){
            slow = nums[slow];
        }
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};