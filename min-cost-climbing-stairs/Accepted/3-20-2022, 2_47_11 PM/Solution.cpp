// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    
    int dp[1015];
    
    int solve(int i , vector<int>&cost)
    {
        if(i >= cost.size())
        {
            return 0;
        }
        
        if(dp[i] !=-1) return dp[i];
        
        dp[i] =  cost[i] + min( solve(i+1 , cost ) , solve(i+2 , cost ) );
       
        return dp[i];
        
    }

    
    int minCostClimbingStairs(vector<int>& cost) {
        
        for(int i=0;i<=cost.size()+9;i++)
            dp[i] = -1;
        
        int cal1 = solve(0 , cost );
        cal1 = min(cal1 , solve(1 , cost ));
        
        return cal1;
        
        
    }
};