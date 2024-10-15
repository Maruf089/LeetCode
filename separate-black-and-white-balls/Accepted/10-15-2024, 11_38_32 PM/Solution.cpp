// https://leetcode.com/problems/separate-black-and-white-balls

class Solution {
public:
    long long minimumSteps(string s) {
        long long Count = 0, zero = 0 ;
        for(int i = s.size()-1;i>=0;i--)
        {
            if(s[i]=='0') zero++;
            else{
                Count += zero;
            }
            
        }
        return Count;
        
    }
};