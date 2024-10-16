// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        
        int dp[50];
        dp[0] = 0 ;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
         //   cout << i << ' ' << dp[i] << endl;
        }
        
        return dp[n];
        
    }
};