/*
ANSWER:

    kiuxaznwbdcaefg
    |   |      |    
   str dup     i
   
str: Start: the starting index of non-duplicated string BEFORE i.
dup: duplicated index: index of previous duplicated character( Stored in dic[i])

Step1: increase length before finding a duplicated char.
Step2: When finding a duplicated char, reset all chars location before that.

*/

class Solution {
public:
    
    int dic[256] = {0};
    
    int lengthOfLongestSubstring(string s) {
        
        fill_n(dic, 256, -1);
    
        int start=0;
        int max_length=0;
        
        for(int i=0; i< s.size(); i++){
            
            if( dic[ s[i] ] >= 0 ){
                
                int dup_index = dic[ s[i] ];
                                
                for(;start <= dup_index; start++){
                   dic[ s[start] ] =-1;
                }
                
                start = dup_index + 1;
            } else {                                
                int length = i - start + 1;                
                if( length > max_length ) {
                    max_length = length;
                }                
            }            
            dic[ s[i] ]  = i;
        }
        
        return max_length;   
    }
};
