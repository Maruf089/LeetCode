// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& vc, int ct) {
        sort(vc.begin(),vc.end());
        int c = 0;
        for(auto it : vc)
        {
            if(ct >= it)
            {
                ct -= it;
                c++;
            }
            else return c;
        }
        return c;
        
    }
};