// https://leetcode.com/problems/earliest-possible-day-of-full-bloom

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int Min = INT_MAX;
        int counT = 0 ;
        for(auto it : plantTime)
            counT += it;
        for(auto it : growTime)
            Min = min(Min , it);
        return counT + Min;
        
    }
};