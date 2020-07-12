/*
ANSWER

             prices  [7,1,5,3,6,4]
min_price_from_left  [7,1,1,1,1,1]
max_price_from_right [7,6,6,6,6,4]


*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> left_scan(prices.size());
        vector<int> right_scan(prices.size());
        
        for(int currentmin = INT_MAX, i=0; i< prices.size(); i++) {            
            if(prices[i] < currentmin) {
                currentmin = prices[i];
            }
            left_scan[i] = currentmin;          
        }
        
        for(int currentmax= INT_MIN, i= prices.size() -1 ; i >=0 ; i--) {            
            if(prices[i] >  currentmax) {
                currentmax = prices[i];
            }
            right_scan[i] = currentmax;          
        }
        
        int ANSWER = 0;
        
        for(int i=0; i < prices.size(); i++) {
            if(right_scan[i] - left_scan[i] > ANSWER)
                ANSWER = right_scan[i] - left_scan[i];
        }
        return ANSWER;
    }
};
