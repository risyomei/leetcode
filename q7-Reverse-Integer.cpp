7-Reverse-Integer


class Solution {
public:
    int reverse(int x) {
        
        int rev = 0;
        
        while(x != 0) {
            
            int remain = x % 10;
            
            /* __int32	4	-2,147,483,648 ～ 2,147,483,647 */
            
            /* Handling for Overflow */
            if( rev > INT_MAX / 10  || (rev == INT_MAX / 10 && remain > 7))
               return 0;
            
            /* Handling for Underflow */
            if( rev < INT_MIN / 10  || (rev == INT_MIN / 10 && remain <-8))
               return 0;
            
            rev *= 10;
            rev += remain;
            x/= 10;
            
        }
        return rev;

    }
};