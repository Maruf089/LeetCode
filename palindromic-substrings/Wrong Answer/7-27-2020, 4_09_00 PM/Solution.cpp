// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
      
      int counT = 0 ;
      if(s.size()==0)
            return counT;
      int dp[s.size()+9][s.size()+9];
      for(int i=0;i<s.size();i++)
      {
          dp[i][i] = 1;
          counT++;
          if(s[i]==s[i+1] and i+1<s.size())
          {
              dp[i][i+1] = 1;
              counT++;
          }
      }
      for(int j = 2;j<s.size();j++)
      {
          for(int i=0;i<j;i++)
          {
              if(dp[i+1][j-1] and s[i]==s[j])
              {
                  dp[i][j] = 1;
                  counT++;
              }
          }
      }
      return counT;
      
    }
};