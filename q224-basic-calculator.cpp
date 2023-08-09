/**
 *
 *  Nothing to say, just a emulation of normal calculation logic
 * 
**/
class Solution {
public:
    int calculate(string s) {

        stack<int> sign;
        stack<int> number;

        int previous_number = 0;
        int current_sign = 1;
        int current_number = 0;

        for( int i=0; i < s.size(); i ++ ){
            if (s[i] == ' ')
                continue;

            if( s[i] >= '0' && s[i] <= '9' ) {
                current_number *= 10;
                current_number += s[i] - '0';
            } else if( s[i] == '-' || s[i] == '+') {
                previous_number += current_sign * current_number;
                current_number = 0;
                current_sign = (s[i] == '+') ? 1 : -1;
            } else if( s[i] == '(') {
                number.push(previous_number);
                sign.push(current_sign);
                previous_number = 0;
                current_sign = 1;
            } else if ( s[i] == ')') {
                previous_number += current_sign * current_number;            
                previous_number = number.top() + sign.top() * previous_number;
                current_number = 0;
                current_sign = 1;
                number.pop();
                sign.pop();
            } else {
                cout << "should not reach here" << endl;
            }
        }

        return previous_number += current_sign * current_number;
    }
};