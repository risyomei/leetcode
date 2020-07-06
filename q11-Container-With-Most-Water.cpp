/*
 
[1,8,6,2,5,4,8,3,7]
 |               |
 i               j

Step1. Calcute Area with i,j above.
Step2(Important). Move min(i,j) center-ward to check if there is a larger area.
(If you move max(i,j) instead of min(i,j), the area will only be smaller.
Step3. Repeat Step2
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0, j=height.size() -1;
        int areaMax = -1;
        
        while(i<j){
            int tempArea = calcualte(height, i, j);

            if(tempArea > areaMax)             
                areaMax = tempArea;
            
            if(height[i] < height[j]){
                i ++;
            }else{
                j --;
            }
               
        }
        return areaMax;
        
    }
    
    int calcualte(vector<int>& height, int i, int j){
        
        int h = min (height[i], height[j]);
        int v = abs(i - j);
        return  h*v;
    }
;
