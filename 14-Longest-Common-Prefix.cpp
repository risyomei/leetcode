14-Longest-Common-Prefix
/*

Vertical Scan

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string answer = "";
        
        if(strs.size() <=0 )
            return answer;
        
        bool ok = true;
        
        
        for(int i; ok; i++) {
            
            if(i >= strs[0].size()){
                ok = false;
                break;
            }
            char current_char = strs[0][i];
            
            for(int j=0; j<strs.size(); j++) {
                if(i >= strs[j].size() || strs[j][i]!= current_char){
                    ok = false;
                    break;
                }
            }
            if(ok)
                answer += current_char;
        }
        return answer;
    }
};
