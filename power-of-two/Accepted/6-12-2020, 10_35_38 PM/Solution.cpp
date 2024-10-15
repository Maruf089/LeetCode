// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if(n==0)
            return false;
        else
      return (floor(log2(n))== ceil(log2(n)));
    }
};