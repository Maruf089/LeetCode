// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int dp[1003][1003];
    int findLength(vector<int>& vc1, vector<int>& vc2) {
        
        int ans = 0;
        for(int i = vc1.size()-1;i>=0;i--)
        {
            for(int j=vc2.size()-1;j>=0;j--)
            {
                if(vc1[i]==vc2[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                ans = max(ans , dp[i][j]);
            }
        }
        return ans;
        
    }
};