// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
      long i = 1 ;
        while(i<n)
        {
            i *= 2;
        }
        return (i==n);
    }
};