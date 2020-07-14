/*
ANSWER:

    Sliding Windows:
    This is a upgraded version of q209
    
    S = "ABABC"
    T= "ABB"
    
    scan T to build a target Dictionary, say
    target['A']=1
    target['B']=2
    target_count=2
        
    scan S. 

State x:
    ABABC
    | |
    i j
Requirement not met, expand j;

State x+1:
    ABABC
    |  |
    i  j
Requirement met, shrink i to find a better answer;

State x+2:
    ABABC
     | |
     i j
Requirement met, shrink i better answer found, shrink i to find a better answer;

State x+3:
    ABABC
      ||
      ij
Requirement not met, expand j;

State x+4:
    ABABC
      | |
      i j
Over;

*/

class Solution {

    int target[256] = {0};        
    int scan[256] = {0};        
    int count = 0;
    int target_count = 0;
    
    void putChar(char s){
        if( target[s] <=  0)
            return;
        
        if( scan[s] + 1 == target[s]) {
            count ++;
        }
        scan[s] ++;        
    }
    
    void removeChar(char s){
        if( target[s] <= 0)
            return;
        
        if( scan[s] == target[s]) {
            count --;
        }
        scan[s] --;
    }
    
    
public:
    string minWindow(string s, string t) {
    
        
        string answer;
        int min = INT_MAX;
        
        // Building Dictionary        
        for(int i=0; i<t.size(); i++){
            if( target[t[i]] == 0 )
                target_count ++;
            target[ t[i] ] ++;
        }

        // Sliding Window                
        int i=0, j=0; 
        putChar(s[0]);
        
        while(true){
            if(count >= target_count){
                
                if( j - i + 1 < min ) {
                    answer = s.substr(i,j - i + 1);
                    min = j - i + 1;
                }            
                removeChar(s[i]);
                i++;
                continue;
                
            } else { // count < target_Count
                
                if(j + 1 >= s.size()){
                    break;
                } else {
                    j++;
                    putChar(s[j]);
                }
            }
        }
        
        if(min == INT_MAX )
            return "";
        return answer;
    }
};
