/*
    First using hashmap to build the <num,freq>
    then use the max heap to find top-K
*/

struct Data {
    int num;
    int freq;
    Data(int num, int freq) {
        this -> num = num;
        this -> freq = freq;
    }
};

struct CompareFreq{
    bool operator()(const Data& p1, const Data& p2) const {
        return p1.freq < p2.freq;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++){
            if( freq.find(nums[i])!=freq.end())
                freq[nums[i]]++;
            else
                freq[nums[i]]=1;
        }

        priority_queue<Data, vector<Data>, CompareFreq> heap;

        for(const auto& pair : freq) {
            heap.push(Data(pair.first, pair.second ));
        }

        vector<int> answer;
        for(int i=0; i<k ; i++) {
            answer.push_back(heap.top().num);
            heap.pop();
        }
        return answer;
    }
};