// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    
    int dp[20004];
    map<int,int>mp;
    
    int solve(int pos ,vector<int>& nums )
    {
        if(pos >= nums.size() ) return 0;
        
        if(dp[pos] != -1) return dp[pos];
        
        int d = 0;
        if(pos + 1 < nums.size()){
            if(nums[pos]+1 < nums[pos+1])
                d = max(d , nums[pos] * mp[nums[pos]] + solve(pos + 1 , nums ) );
                d = max(d , nums[pos] * mp[nums[pos]] + solve(pos + 2 , nums ) );
            }
        else  d = max(d , nums[pos] * mp[nums[pos]] + solve(pos + 1 , nums ) );
        
        return dp[pos] = d;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        
        for(auto it : nums)
            mp[it]++;
        
        set<int> s;
        int size = nums.size();
        for( int i = 0; i < size; ++i ) s.insert( nums[i] );
        nums.assign( s.begin(), s.end() );
        
        memset(dp , -1 , sizeof(dp) );
        
        int ans = nums[0] * mp[nums[0]];
        for(int i=0;i<nums.size();i++)
        {
            ans = max(ans , solve(i,nums) );
        }
        
        return ans ;
        
        
    }
};