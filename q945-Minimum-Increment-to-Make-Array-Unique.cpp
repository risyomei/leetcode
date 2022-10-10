q945-Minimum-Increment-to-Make-Array-Unique
/*

nums: 1, 1, 2, 2, 3, 7, 7, 8, 9, 10
Tgt:  1, 2, 3, 4, 5, 7, 8, 9,10, 11
Anwer:0, 1, 1, 2, 2, 0, 1, 1, 1, 1 = 10

*/


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        int min = nums[0];
        
        for(int i = 0; i < nums.size(); i++ ) {
            
            if(min < nums[i])
                min = nums[i];
            
            answer += (min++ - nums[i]);            
        }
        
        return answer;
        
    }
};