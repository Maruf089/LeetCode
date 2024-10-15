// https://leetcode.com/problems/house-robber

class Solution {
public:
    
    int dp[101];
    int solve(int pos, vector<int>& nums)
    {
        if(pos>=nums.size()) return 0;
        
        if(dp[pos] != -1)  return dp[pos];
        
        int d = 0;
       
        d =  nums[pos] + solve(pos + 2 , nums)  ;
        d =  max( d , solve(pos + 1 , nums) );
        
        
        return dp[pos] = d;
        
        
    }
    int rob(vector<int>& nums) {
     
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};