// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(ll x)
    {
    return ((1LL<<(long long)log2(x))==x);
    }
};