// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    
    int dp[1001];
    
    int solve(int i , vector<int>&cost)
    {
        if(i >= cost.size())
        {
            return 0;
        }
        
        if(dp[i]==-1){
            dp[i] =  cost[i] + min( solve(i+1 , cost ) , solve(i+2 , cost ) );
            return dp[i];
        }
        
        return dp[i];
        
    }
    
    int f(int n,vector<int>&cost)
    {
        if(n==cost.size()-1)
            return cost[n];
        else if(n>=cost.size())
        return 0;
        if(dp[n]==-1)
        {
            dp[n]=cost[n]+min ( f(n+1,cost) ,f(n+2,cost) );
            return dp[n];
        }
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        for(int i=0;i<=cost.size()+9;i++)
            dp[i] = -1;
        
     //   return min(f(0,cost),f(1,cost));
        
        
        int cal1 = solve(0 , cost );
        cal1 = min(cal1 , solve(1 , cost ));
        
        return cal1;
        
        
    }
};