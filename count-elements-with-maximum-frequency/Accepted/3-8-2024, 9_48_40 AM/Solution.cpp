// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& vc) {
        int Max = 0;
        map<int,int>mp;
        for(auto it : vc){
            mp[it]++;
            if(mp[it] > Max)
              Max = mp[it];
        }
        int cnt = 0;
        for(auto it : vc){
            if(mp[it]==Max)
            {
                cnt += Max;
                mp[it] = 0;
            }
        }
        return cnt;

        
    }
};