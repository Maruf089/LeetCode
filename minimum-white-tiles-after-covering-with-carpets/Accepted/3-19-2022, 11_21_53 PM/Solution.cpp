// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets

class Solution {
public:
    
    int dp[1005][1005];
    
    int solve(int i,string &s , int ase , int len)
    {
        if(i >= s.size()) return 0;
    
        if(dp[i][ase] != -1) return dp[i][ase];
    
        int d = INT_MAX ;
        if(s[i]=='0') 
            d =  min(d , solve(i+1, s, ase, len) ) ;
        else
        {
            d = min(d , 1 + solve(i+1 , s , ase , len) );
            if(ase > 0)
            d =  min(d , solve(i+len, s, ase-1, len) ) ;
        }
    
        return dp[i][ase] = d;
    
    }
    
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        memset(dp , -1 , sizeof(dp));
        return solve(0,floor,numCarpets,carpetLen);
    }
    
    
};