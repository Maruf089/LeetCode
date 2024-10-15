// https://leetcode.com/problems/jump-game

class Solution {
public:
  
    bool canJump(vector<int>& nums) {
        
       int x = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(x < i) return false;
            x = max(x , i + nums[i]);
        }
        return true;
        
    }
};

/*

class Solution {
public:
    int dp[10009];
    bool can(int pos,vector<int>& nums)
    {
        
        if(pos>nums.size()-1 or nums[pos]==0) return false;
        
        if( nums.size() - 1 - pos <= nums[pos] ) return true;
        
        if(dp[pos]!=-1) return dp[pos];
        
        dp[pos] = 0;
        for(int i=1;i<=nums[pos];i++)
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

*/
