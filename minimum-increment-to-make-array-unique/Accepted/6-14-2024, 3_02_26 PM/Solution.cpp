// https://leetcode.com/problems/minimum-increment-to-make-array-unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& vc) {
        int maxNow = 0, count = 0;
        sort(vc.begin(),vc.end());
        for(int i=0;i<vc.size();i++)
        {
            maxNow = max(maxNow , vc[i]);
            count += (maxNow - vc[i]);
            maxNow += 1;
            
        }
        return count;
        
    }
};