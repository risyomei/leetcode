20-Valid-Parentheses

class Solution {
public:
    inline bool pair(char l, char r) {
        if(l == '{' && r == '}')
            return true;
        if(l == '[' && r == ']')
            return true;
        if(l == '(' && r == ')')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        vector<char> stack;
        
        for(int i = 0; i < s.size(); i++ ) {
            
            if( s[i] == '[' || s[i] == '(' || s[i] == '{'){
                stack.push_back(s[i]);
                continue;
            }
            
            if( stack.empty() || !pair(stack.back(),s[i]) ) {
                return false;    
            }
            stack.pop_back();
        }
        if(stack.empty())
            return true;
        return false;
    }
};