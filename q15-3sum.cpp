class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v = {};
        
        if(nums.size()<3)
            return v;
        
        sort(nums.begin(), nums.end());
        
        for ( int i = 0; i < nums.size() - 2; i++ ) {
            
            
            if( i > 0 && nums[i-1] == nums[i] ) {
                // Skip the Possible Duplicates on the Left Side
                continue;
            }
            
            int L = i + 1;
            int R = nums.size() - 1;
            
            while ( L < R ){
                if( nums[i] + nums[L] + nums[R] < 0 )
                    L++;
                else if( nums[i] + nums[L] + nums[R] > 0 )
                    R--;
                else {
                    // At this point, One of the Answer is found
                    vector<int> temp = {nums[i],nums[L],nums[R]};
                    v.push_back(temp);
                
                    // Skip the Possible Dulicates on the Right Side
                    while( L < R && nums[R-1] == nums[R])
                        R--;
                    L++;
                    R--;    
                }
            } 
        }
        return v;
    }
};
