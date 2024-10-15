// https://leetcode.com/problems/jump-game

class Solution {
public:
    int dp[10009];
    bool can(int pos,vector<int>& nums)
    {
        if( nums.size() - 1 <= pos ) return true;
        
        if( nums[pos]==0) return false;
        
        
        
        if(dp[pos]!=-1) return dp[pos];
        
        dp[pos] = 0;
        for(int i=nums[pos];i>=1;i--)
        {
            dp[pos] |= can(pos + i , nums);
        }
        return dp[pos];
    }
    
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1) return true;
        memset(dp,  -1 ,sizeof(dp));
        return can(0,nums);
        
    }
};