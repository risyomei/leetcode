class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> test;

        int from_previous = 0;

        A[A.size() - 1 ] += K;

        for( int index = A.size()-1; index >=0 || from_previous >0; index--) {

            int current_digit = 0;

            if(index >= 0) {
                current_digit += A[index];
            }

            current_digit += from_previous;

            // this digit
            test.push_back( current_digit % 10 );

            // next carry
            current_digit /= 10;
            from_previous = current_digit;
        }


        reverse( test.begin(), test.end());
        return test;
    }
};
