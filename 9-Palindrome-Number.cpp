9-Palindrome-Number

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0 || (x%10==0 && x!= 0))
            return false;
        
        int reverse=0;
        
        while(x>reverse){    
            reverse *= 10;
            reverse += x%10;
            x/=10;
        }
        
        if(reverse == x || reverse/10 == x)
            return true;
        return false;   
    }
};