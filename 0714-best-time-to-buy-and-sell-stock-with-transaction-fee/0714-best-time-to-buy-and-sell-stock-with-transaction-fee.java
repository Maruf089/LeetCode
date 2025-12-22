class Solution {
     public int solve(int idx , int buy, int[] prices, int [][] dp, int fee){
        // Time Com : O(n*2)
        // Space Com : O(n*2) + O(n)
        if(idx >= prices.length) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy==1){
            // buy
            // you have 2 possibilities either take that or not take 

            dp[idx][buy] = Math.max(-prices[idx] - fee +solve(idx+1,0,prices,dp,fee)
            , solve(idx+1,1,prices,dp,fee));
        }
        else{
            // sell
            // you have 2 possibilities either take that or not take 

            dp[idx][buy] = Math.max(prices[idx]+solve(idx+1,1,prices,dp,fee)
            , solve(idx+1,0,prices,dp,fee));
        }

        return dp[idx][buy];
        
    }
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int [][] dp = new int[n+1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = -1;
            }
        }
        return Math.max(0 , solve(0,1,prices,dp,fee));
    }
}