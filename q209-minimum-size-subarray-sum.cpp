/*
ANSWER:

    This is a two pointer problem:

    when sum is smaller than target, move j forward to increase sum.


State X:
    [2,3,1,2,4,3]
     |   |
     i   j

because sum = 6 (2+3+1) < target = 7,
then move j forward to increase sum to find a POSSIBLE answer.

State X+1:
    [2,3,1,2,4,3]
     |     |
     i     j
Because sum = 8 (2+3+1+2) > target = 7,
move i forward to find a possible shorter length,
which could be a BETTER answer.

*/




class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        if (nums.size() <= 0)
            return 0;

        int answer = INT_MAX;
        int i=0, j=0;
        int sum = nums[0];

        while( true ){
            if(sum>=s) {
                if(i==j){
                    return 1;
                } else { // j>i ( i>j is not possible)
                    answer = min(j - i + 1, answer);
                    sum -= nums[i];
                    i++;
                    continue;
                }
            } else { // sum < s
                if(j + 1 >= nums.size()) {
                    break;
                } else {
                    j++;
                    sum += nums[j];
                }
            }
        }

        if( answer == INT_MAX)
            return 0;
        return answer;
    }
};
