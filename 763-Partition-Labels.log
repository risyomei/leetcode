763-Partition-Labels

struct Zone{
    int start = -1;
    int end = -1;
    Zone(){}
    Zone(int x, int y){start = x;end=y;}
};


class Solution {
    struct sort_on_start {
        inline bool operator() (const Zone& lx, const Zone& rx ) {
            return lx.start < rx.start;
        }
    };

public:
    vector<int> partitionLabels(string s) {
        
        vector<int> answer;
            if(s.size()<=0)
        return  answer;
        
        vector<Zone> dic(26); 
        
        /* 
            Remember the Start Point and End Point of each letter 
            (e.g. 'a' start index =1, end index = 8) 
        */
        for(int i=0; i< s.size(); i++) {            
            int index = s[i] - 'a';                        
            if( dic[index].start <0 )
                dic[index].start = i;
            dic[index].end=i;   
        }
        
        /*
            Sort the Array so that letter with smaller start index comes first.
            At this point, this problem was translated to q56 "Merge Intervals"            
        */
        sort(dic.begin(), dic.end(), sort_on_start());
        
        vector<Zone> merged_zones;
        merged_zones.push_back(Zone(0,0));
        
        for(int i=0;i<dic.size();i++) {
            if(dic[i].start<0)
                continue;
            
            //cout<< dic[i].start << "  " << dic[i].end << endl;
            if (dic[i].start <= merged_zones.back().end) {
                if(dic[i].end >= merged_zones.back().end) {
                    merged_zones.back().end = dic[i].end;
                }
            }
            else {
                merged_zones.push_back(Zone(dic[i].start,dic[i].end));
            }
        }
        /*
            Calculate the Length of Merge Zones       
        */
        
        //cout << "----------" <<endl;
        for(int i=0;i<merged_zones.size();i++) {
            //cout<< merged_zones[i].start << "  " << merged_zones[i].end << endl;
            int zone_len = merged_zones[i].end  - merged_zones[i].start + 1;
            answer.push_back(zone_len);
        }
        
        return answer;
    }
};