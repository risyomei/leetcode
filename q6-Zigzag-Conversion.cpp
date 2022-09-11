6-Zigzag-Conversion
/*

Nothing to say about it..

*/
class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;
        
        string answer="";
        int fixed_offset = (numRows - 1) * 2;
        
        for(int i=0; i<numRows; i++) {
            
            int start_offset = i;
            while( start_offset < s.size() ){
                
                answer += s[start_offset];
                
                int offset_in_middle = fixed_offset - (2 * i);
                
                if(i!=0 && offset_in_middle !=0 && start_offset + offset_in_middle < s.size())
                    answer += s[start_offset + offset_in_middle];
                
                start_offset += fixed_offset;
            }
        }
        return answer;
    }
};