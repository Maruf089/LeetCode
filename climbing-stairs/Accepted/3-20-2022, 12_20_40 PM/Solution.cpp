// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    
    int dp[50][50];
    
    int solve(int sum,int n)
    {
        if(sum==n) return 1;
        if(sum > n ) return 0;
        
        if(dp[sum][n] != -1 ) return dp[sum][n];
        
        return dp[sum][n] =  solve(sum+1,n) + solve(sum+2,n);
    }
    int climbStairs(int n) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
        
    }
};