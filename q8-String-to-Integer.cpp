8-String-to-Integer
class Solution {
public:
    int myAtoi(string s) {
        
        //Trimming WhiteSpaces/Unwanted Chars
        size_t startpos = s.find_first_not_of(" \t");
        if( string::npos != startpos ) {
            s = s.substr( startpos );
        }
      
        int flag = 1;
        int i = 0;
        
        if ( s.size() <=0 )
            return 0;
        
        //Reading Heading Character
        if( s[0]=='+') i++;
        else if( s[0]=='-' ){
            flag = -1;
            i++;
        }
        
        long answer=0;        
        for(;i<s.size();i++){
            
            if(s[i] >'9' || s[i]<'0')
                break;
            
            answer *= 10;
            answer += (s[i] - '0');
            
            if(flag > 0 && answer > INT_MAX)
                return INT_MAX;
            
            if(flag < 0 && answer * flag < INT_MIN)
                return INT_MIN;
        }
        return answer * flag;
    }
};