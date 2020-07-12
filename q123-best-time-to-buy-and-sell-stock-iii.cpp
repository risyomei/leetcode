/*
ANSWER:

Divide array into two sections, each stands for a transaction (1 buy and 1 sell)

Left_max_array: the max profit for FIRST transaction if the transaction finished before day i,  
Right_max_array: the max profit for SECOND transaction if the transaction started after day i,  

index:                  0	1	2	3	4	5	6	7	8	9
----------------------------------------------------------------
Original Input			1	2	4	2	5	7	2	4	9	0
Left_max_arrary			0	1	3	3	4	6	6	6	8	8	
Right_max_array			8	7	7	7	7	7	7	5	0	0	

eg. 
Left_max_arrary[3] == 3, because max profit can be earned by buying at 1 (index == 0) and selling at 4 (index == 2)
Right_max_arrary[7] == 5, because max profit can be earned by buying at 4 (index == 7) and selling at 9 (index == 9)

now, find a index i to maximize (max_from_left[i] + max_from_right[i])
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        if(prices.size()<=1)
            return 0;
        
        vector<int> max_from_left(prices.size());
        max_from_left[0]=0;
        vector<int> max_from_right(prices.size());
        max_from_right[prices.size()-1]=0;
        
        // Genereate Left_max_array
        for(int i=1,curmin=prices[0]; i<prices.size(); i++) {
            
            if( prices[i] - curmin > max_from_left[i-1]) {
                max_from_left[i] = prices[i] - curmin;
            } else {
                max_from_left[i] = max_from_left[i-1];
            }
            
            if( prices[i] < curmin) {
                curmin = prices[i];
            }
        }
       
        // Generate Right_max_array 
        for(int i=prices.size()-2,curmax=prices[prices.size()-1]; i>=0; i--) {
            
            if( curmax - prices[i] > max_from_right[i+1]) {
                max_from_right[i] = curmax - prices[i];
            } else {
                max_from_right[i] = max_from_right[i+1];
            }
            
            if( prices[i] > curmax) {
                curmax = prices[i];
            }
        }
       
        // Find argmax( Left_max_array[i] + Right_max_array[i] )
        int answer = INT_MIN;
        for(int i=0; i < prices.size(); i++ ){
            if(max_from_left[i] + max_from_right[i] > answer) {
                answer = max_from_left[i] + max_from_right[i];
            }
        }
        
        return answer;
    }
};
