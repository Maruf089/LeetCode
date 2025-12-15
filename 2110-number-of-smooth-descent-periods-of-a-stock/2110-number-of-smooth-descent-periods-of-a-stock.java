class Solution {
    public long getDescentPeriods(int[] prices) {
        int logest_decent = 1;
        long res = 1;
        if (prices.length == 1)
            return 1;

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] + 1 == prices[i - 1]) {
                logest_decent++;
                res += logest_decent;
            } else {

                logest_decent = 1;
                res++;
            }
        }
        return res;

    }
}