class Solution {
    public int maxProfit(int[] p) {
        int ans = 0 ;
        int now_min = p[0];
        for(int i=1; i< p.length ; i++){
            ans = Math.max(ans , p[i] - now_min);
            now_min = Math.min(now_min , p[i]);
        }
        return ans;
        
    }
}