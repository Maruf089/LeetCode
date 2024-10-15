// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    
    int dp[20009];
    map<int,int>mp;
    
    int solve(int pos)
    {
        if(pos >= 20001 ) return 0;
        
        if(dp[pos] != -1) return dp[pos];
        
        int d = 0;
        d = mp[pos] * pos + solve(pos + 2);
        d = max(d , solve(pos + 1));
        
        return dp[pos] = d;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        
        for(auto it : nums)
            mp[it]++;
        
        memset(dp , -1 , sizeof(dp) );
        
        int ans = mp[1];
        ans = max(ans , ans + solve(3)); /// start from 1 then 3
        ans = max(ans , solve(2));  /// start from 0 then 2
        
        return ans ;
        
        
    }
};