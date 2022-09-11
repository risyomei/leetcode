258-Add-Digits
/*
    Consider 5 digit number '12345'
    
    12345 = 1 * 10000 + 2 * 1000 + 3 * 100 + 4 * 10 + 5
          = 1 * (1 +9 * 1111) + 2 *（1 + 9 * 111） + 3 *（1 + 9 * 11） + 4 * (1 + 9*1) + 5
          = 1*1 + (1 * 9 * 1111) + 2*1 + (2 * 9 * 111) + 3*1 + (3 * 9 * 11） + 4*1 + (4 * 9 * 1) + 5
          = 1 + 2 + 3 + 4 + 5 + 9 * (1*1111 + 2*111 + 3*11 + 4*1)  
*/




class Solution {
public:
    
    
/*
    Loop Solution
    int addDigits(int num) {
        
        string num_string;        
        do {
            num_string = to_string(num);
            num = 0;
            for(int i=0;i<num_string.size();i++){                
                num += num_string[i] - '0';
            }
        } while (num_string.size() >= 2);
        return num;
    }
*/
    int addDigits(int num) {
        if(num<10)
            return num;
        
        if(num%9==0)
            return 9;
        return num%9;
    }
    
    
};