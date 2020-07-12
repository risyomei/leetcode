// 滑动窗口
// two pointer
// sliding window 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        char dic[512] = {0};
        
        int i=0, j=0; 
        int max = 0;
        
        while (i < s.size() && j <s.size() ) {
            
            // Newly found number does not exists
            // found a new max
            if( dic[ s[j] ] <= 0) {
                dic[ s[j] ] ++;
                j++;
                max = (j - i) > max ? (j - i) : max;
            }
            else {
                dic[ s[i] ] --;
                i++;               
            }                            
        }
        return max;
    }
};
