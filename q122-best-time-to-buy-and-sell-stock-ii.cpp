/*
ANSWER:
  This is pretty straight forward.

  buy before the price goes up,
  sell before the price goes down.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyPrice = -1;
        int sum = 0;
        
        vector<int> prices_exp(prices);
        prices_exp.push_back(prices.back());
        
        for(int i=0; i<prices.size(); i++){
                    
            // not holding any stock, buy if price is about to goes up
            if( buyPrice < 0 && prices_exp[i+1] > prices_exp[i]) {
                buyPrice = prices_exp[i];
                continue;
            }
            
            // holding a staock, sell if price is about to goes down
            if( buyPrice >= 0 && prices_exp[i+1] <= prices_exp[i]) {
                sum += prices_exp[i] - buyPrice;
                buyPrice = -1;
                continue;
            }
        }
        return sum;
    }
};
