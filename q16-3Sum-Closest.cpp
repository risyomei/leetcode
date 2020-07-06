/*

ANSWER:
[-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33]
0

[-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33]
  |   |                               |
  i   j                               k

loop: i from -55 all the way to 33
     for i + 1 .... last do classic two pointer

*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int nearest = INT_MAX;        
        int answer = INT_MAX;
        sort(nums.begin(), nums.end()); 
        
        for(int i=0; i< nums.size(); i++){
            
            int j = i + 1; 
            int k = nums.size() - 1;             
            
            while( j < k ){
                
                int sum  = nums[i] + nums[j] + nums[k];
                int diff = abs( target - sum );
                
                if( abs( target - sum ) <= nearest) {
                    nearest = abs( target - sum );                    
                    answer = nums[i] + nums[j] + nums[k];
                }
                
                if( sum < target ) {
                    j++;
                } else if ( sum > target ) {
                    k--;
                } else {
                    return target;
                }
                        
            }
        }    
        return answer;
    }
};
