// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& vc) {
        int Max = 0;
        int mp[101] = {0};
        for(auto it : vc){
            mp[it]++;
            Max = max(Max, mp[it]);
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