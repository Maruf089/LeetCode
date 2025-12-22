class Solution {
    public int maxProfit(int[] prices) {
        int till_Max[] = new int[prices.length + 9];
        for(int i = 0; i < till_Max.length; i++) {
            till_Max[i] = 0;
        } 

        till_Max[prices.length] = prices[prices.length-1];
        int ans = 0;
        for(int i=prices.length-1;i>=0;i--)
        {
            till_Max[i] = Math.max(till_Max[i+1],prices[i]);
        }
        for(int i=prices.length-1;i>=0;i--){
            ans = Math.max(ans , ( till_Max[i+1] - prices[i]));
        }


        return ans;
        
    }
}