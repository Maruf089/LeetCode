 bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] < b[1];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& vc) {
        int c = 0;
        sort(vc.begin(),vc.end(), cmp);
        int prev = -INT_MAX;
        for(auto it : vc)
        {
            if(it[0] < prev) c++;
            else prev = it[1];
        }

      return c;
    }
};
