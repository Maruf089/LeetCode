// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        int count = 0 ;
        string tmp = text;
        tmp = pattern[0] + text;
        

        
        int a = 0 ;
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]==pattern[0]) a++;
            else if(tmp[i]==pattern[1])
            {
                count += a;
            }
        }
        
 
        
        int counT = 0 ;
        
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