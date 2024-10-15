// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& vc) {
        int Max = 0;
        map<int,int>mp;
        for(auto it : vc){
            mp[vc[it]]++;
            Max = max(Max, mp[vc[it]]);
        }
        int cnt = 0;
        for(auto it : vc){
            if(mp[vc[it]]==Max)
            {
                cnt += Max;
                mp[vc[it]] = 0;
            }
        }
        return cnt;

        
    }
};