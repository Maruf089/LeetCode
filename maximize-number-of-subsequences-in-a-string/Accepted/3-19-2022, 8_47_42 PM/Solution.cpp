// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long count = 0 ;
        string tmp = text;
        tmp = pattern[0] + text;
        

        
        long long a = 0 ;
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]==pattern[0]) a++;
            else if(tmp[i]==pattern[1])
            {
                count += a;
            }
        }
        
        if(pattern[0]==pattern[1])
        {
            count = (a * (a-1) ) / 2 ;
        }
        
 
        
        long long counT = 0 ;
        
        tmp = text;
        tmp = text + pattern[1];
        a = 0 ;
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]==pattern[0]) a++;
            else if(tmp[i]==pattern[1])
            {
                counT += a;
            }
        }
        
        
     
        
        return max(counT,count);
        
        
        
        
    }
};