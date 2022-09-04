43-Multiply-Strings

class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1[0]=='0' || num2[0]=='0')
            return "0";
        
        int level = 0;
        string final_answer = "";
        for(int i = num2.size() - 1; i >= 0; i--){
            int carry = 0;
            string answer = "";
            
            /*  Multiplication for single Level */ 
            for(int j=num1.size() - 1; j >= 0; j--){
                
                int value = (int)(num2[i] - '0') * (int)(num1[j] - '0') + carry;
                carry = value / 10;
                value %= 10; 
                answer = to_string( value ) + answer;
            }
            if(carry!=0)
                answer = to_string( carry ) + answer;
            for(int m = 0; m < level; m++)
                answer += "0";
            level++;
            
            /* Addition to previous Answer */
            carry = 0;
            
            string temp = "";
            for(int x = final_answer.size()-1,y = answer.size()-1; x>=0 || y>=0; x--,y-- ){
                int value = ((x >= 0)? (final_answer[x] - '0'):0) + ((y >= 0)? (answer[y] - '0'):0) + carry;
                carry = value / 10;
                value %= 10;
                
                temp = to_string( value )  + temp;   
            }
            if(carry!=0) 
                temp = to_string( carry ) + temp;
            final_answer = temp;
        }
        
        return final_answer;
        
    }
};