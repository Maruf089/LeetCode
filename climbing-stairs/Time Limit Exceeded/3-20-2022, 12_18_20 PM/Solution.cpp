// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    
    int solve(int sum,int n)
    {
        if(sum==n) return 1;
        if(sum > n ) return 0;
        
        return solve(sum+1,n) + solve(sum+2,n);
    }
    int climbStairs(int n) {
        
        int dp[50];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
  return solve(0,n);
        
    }
};