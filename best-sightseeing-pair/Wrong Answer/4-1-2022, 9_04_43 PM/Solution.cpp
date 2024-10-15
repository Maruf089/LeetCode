// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        
        int n = v.size() , Max = -10000;
        vector<int>pre_max(n+1) , suff_max(n+1);
        
        for(int i = 0 ;i < n ; i++)
        {
            pre_max[i] = max(pre_max[max( 0, i-1 ) ] , v[i] + i);
        }
        for(int i = n-1;i>=0;i--)
        {
            suff_max[i] = max(suff_max[i+1] , v[i] - i);
        }
        for(int i = 0 ;i < n-1 ; i++)
        {
            Max = max( pre_max[i]  + suff_max[i+1] , Max );
        }
        
        return Max;
    }
};