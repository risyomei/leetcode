class Solution {
public:
    bool isHappy(int n) {
        
        if(n<=0)
            return false;
        
        int slow = digitSum(n);
        int fast = digitSum(digitSum(n));
        do{                        
            slow = digitSum(slow);
            fast = digitSum(digitSum(fast));
        }while(slow!=fast);
        
        if(fast!=1)
            return false;
        return true;
    }
    
    int digitSum(int input){
        int sum = 0;
        while( input > 0 ){
            int last = input % 10;
            sum += last * last;
            input /= 10;
        }
        sum += input * input;
        return sum;
    }
};
