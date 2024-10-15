// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    
    int dp[101];
    int solve(int pos, vector<int>& nums , int sz)
    {
        if(pos>=sz) return 0;
        
        if(dp[pos] != -1)  return dp[pos];
        
        int d = 0;
       
        d =  nums[pos] + solve(pos + 2 , nums , sz)  ;
        d =  max( d , solve(pos + 1 , nums, sz) );
        
        
        return dp[pos] = d;
        
        
    }
    int rob(vector<int>& nums) {
     
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,nums,nums.size()-1);
        
        memset(dp,-1,sizeof(dp));
        ans = max(ans , solve(1,nums,nums.size()) ) ;
        
        return ans;
    }
};