// hash
struct Data {
    int index;
    int value;
};

class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> answer;
        
        vector<Data> dataArray;
        
        for( int i = 0; i < nums.size(); i++) {
            Data temp;
            temp.index = i;
            temp.value = nums[i];         
            dataArray.push_back(temp);
        }
        
        
        sort( dataArray.begin(), dataArray.end(), [](Data a, Data b) {
            return a.value < b.value ;   
        });
        
        int i = 0, j = nums.size() -1;
        
        do{
            if( dataArray[i].value + dataArray[j].value == target){
                answer.push_back( dataArray[i].index );
                answer.push_back( dataArray[j].index );
                return answer;
                
            }else if( dataArray[i].value + dataArray[j].value < target ){
                i++;
            }else {
                j--;
            }
            
            
        } while  ( i < j);
        
        return answer;
    }
};
