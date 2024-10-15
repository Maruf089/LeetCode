// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int now_min = p[0] , now_max = p[0];
        int ans = 0 ;
        
        for(int i=1;i<p.size();i++)
        {
                ans =  max(ans , p[i] - now_min);
                now_min = min(now_min , p[i]);
        }
        return ans;
        
    }
};