172-Factorial-Trailing-Zeroes

/*

5! = 1 * 2 * 3 * 4 * 5; 
And you will see that the trailing zeros can only produced by 
5 * N where N is the positive integer.

So now the problem becomes that How many time, the N(input integer) can be divided by 5;


1  2  3  4  5
            *
6  7  8  9  10
            *
11 12 13 14 15
            *
16 17 18 19 20
            *
21 22 23 24 25
            *

The 25 = 5 * 5 which contains two '5's, 
but consider that the 25 is also divisible by 5, 
which is already counted as once in n/5.

That's the same for 125, which is counted in n/5 and n/25..


*/

class Solution {
public:
    int trailingZeroes(int n) {
        return n/5 + n/25 + n/125 + n/625 + n/3125;
    }
};