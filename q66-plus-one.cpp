class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ndit = digits.size();
        digits[ndit-1]++;

        bool plusone = false;

        for(int i = ndit-1; i>=0; i--)
        {
            if(plusone)
                digits[i]++;

            if(digits[i] >= 10)
                plusone = true;
            else
                plusone = false;

            digits[i] %= 10;
        }

        if(plusone)
        {
            vector<int> newarray(ndit+1,1);
            for(int i = 1; i<=ndit; i++)
                newarray[i] = digits[i-1];

            return newarray;
        }
        return digits;
    }
};
