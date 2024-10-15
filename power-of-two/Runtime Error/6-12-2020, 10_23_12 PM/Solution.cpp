// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return ((1LL<<(long long int)log2(n))==n);
    }
};