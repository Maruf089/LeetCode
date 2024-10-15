// https://leetcode.com/problems/earliest-possible-day-of-full-bloom

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>>vc;
        
        int Min = INT_MAX;
        int counT = 0, highest = 0 ;
        
        for(int i = 0 ; i < plantTime.size(); i++ )
        {
            vc.push_back( {growTime[i] , plantTime[i] } );
        }
        sort(vc.begin() , vc.end());
        reverse(vc.begin() , vc.end());
        
        for(int i = 0 ; i < vc.size(); i++ )
        {
            counT += vc[i].second;
            highest = max( highest , counT + vc[i].first ) ;
            
        }
        
        
        
        return counT + abs(highest - counT);
        
    }
};