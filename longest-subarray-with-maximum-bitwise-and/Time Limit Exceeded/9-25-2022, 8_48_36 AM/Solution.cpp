// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

class Solution {
public:
    int longestSubarray(vector<int>& vc) {
        
        int Max = 0 ;
        for(auto it : vc)
        {
            Max = max(Max , it);
        }
        
        int len = 1;
        for(int i = 0 ; i < vc.size() ; i++)
        {
            int A = Max;
            int counT = 1 ;
            
            if(vc[i]==Max)
            {
                for(int j = i-1 ; j>= 0 ; j--)
                {
                    if( (A & vc[j]) == Max)
                        counT++;
                    else break;
                }
                
                for(int j = i + 1;j<vc.size();j++)
                {
                  
                    if( (A & vc[j]) == Max)
                        counT++;
                    else break;
                }
               
            }
            
            len = max(len , counT);
        }
        
        
        return len;
        
    }
};