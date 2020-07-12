/*

ANSWER: DynamicProgramming
 
input: nums   [-2,1,-3,4,-1,2,1,-5,4]
                  |  
                  i

Max_array:    [-2,1,-2,4, 3,5,6, 1,5]

given the Max_sub_array( [nums[0] .... nums[n-1]] ) and nums[n], 
the Max_sub_array( [nums[0], .... , nums[n-1], nums[n]] ) can be calculated as follow:

 if(    Max_sub_array( [nums[0] .... nums[n-1]] ) < 0   ) then  
    Max_sub_array( [nums[0] .... nums[n-1], nums[n] ) = nums[n];
 else
    Max_sub_array( [nums[0] .... nums[n-1], nums[n] ) = nums[n] + Max_sub_array( [nums[0] .... nums[n-1]] ) 


*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
        if(nums.size()<=0)
            return 0;
        
        int previousMax = 0;
        int max = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            
            if( previousMax > 0){
                nums[i] += previousMax;
            }
            previousMax = nums[i];
            
            if(nums[i] > max) {
                max = nums[i];    
            }
        }
        return max;
    }
};
