/*
ANSWER:

Key idea:

The amount of water that can be trapped is decided by the shorter edge (instead of longer edge).
Therefore, it is always safe to move shorter edge centerwise

*/
class Solution {
public:
    int trap(vector<int>& height) {
        
        int i = 0;
        int j = height.size() - 1;
        
        int left_max = 0;
        int right_max = 0;
        
        int answer = 0;
        
        while( i < j ){
            
            if( height[i] < height[j] ){                
                if( height[i] < left_max ) {                    
                    answer += (left_max - height[i]);
                } else{
                    left_max = height[i];
                }                        
                i++;
            } else { // height[j] >= height[i] 
                if( height[j] < right_max ) {                    
                    answer += (right_max - height[j]);
                } else{
                    right_max = height[j];
                }                        
                j--;
            }
        }
        return answer;
    }
};
