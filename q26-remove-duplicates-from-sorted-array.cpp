/*
ANSWER:
     Always use i to record last non-duplicates.
     Always use j to check next
     [0,0,1,1,1,2,2,3,3,4]
      | |
      i j 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() < 2)
            return nums.size();
        
        int i = 0, j = 1;
        
        for( ; j < nums.size(); j++) {
            if( nums[i] != nums[j]) {
                i ++; 
                nums[i] = nums[j];                
            }
        }
        return i + 1;
    }
};
