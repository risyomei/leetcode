q32-Longest-Valid-Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        
        if( s.size() <=1 )
            return 0;
        
        int max_len = 0;
        vector<int> dp(s.size(), 0);
 
        for(int i=1; i<s.size(); i++) {
            
            if( s[i] == '(' ) {
                dp[i] = 0;
                continue;
            }
            
            //Now: s[i] == ')'

            if( s[i-1] == '(') {
                //
                // Found a "()", Current Length is updated to 2
                // 
                // e.g.
                // From (())()
                //      00240?
                //           *
                //
                // To   (())()
                //      002402
                //           * here: The length is updated because "()" is valid sequence with length = 2
                dp[i] = 2;   

            } else { //s[i-1] == ')' 
                //
                // Found a "))"
                //
                // In the "))"
                //         *: if the formar ')' is an end of valid parenthis sequence with length dp[i-1],
                //              And, if there is '(' to match the current ')' 
                //              then we should Add 2 to that length dp[i-1].
                // 
                // e.g.
                // From (()())
                //      00204?
                //           *: 
                // To   (()())
                //      002046
                //           *: here: "()()" is valid sequence with length of 4
                //              We also have a '(' before "()()",
                //              Therefore, the valid length is 6 now.
                //              
                int last_matching = i - dp[i-1] - 1;      
                if( last_matching >= 0 && s[last_matching] == '(') {
                    dp[i] = dp[i - 1] + 2;
                }
            } 
            // 
            // e.g.
            // From (())()
            //      002402
            //
            // To   (())()
            //      002406
            //           * here: 
            if( i - dp[i] >=0 ){
                dp[i] += dp[i - dp[i]];
            }
            
            // Update Max
            max_len = max_len < dp[i] ? dp[i]: max_len;
        }
        
        return max_len;
    }
};