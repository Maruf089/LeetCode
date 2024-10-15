// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        
      int dp[50];
        dp[0] = 0 ;
        dp[1] = 1;
        
        for(i=2;i<=n;i++)
            dp[i] = dp[i-1] + do[i-2];
        
        return dp[n];
        
    }
};