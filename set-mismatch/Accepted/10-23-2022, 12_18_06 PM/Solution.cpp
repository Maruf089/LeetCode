// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int xor00 = 0, xor0 = 0, xor1 = 0;
        
        for (int n: nums)
            xor00 ^= n;
        for (int i = 1; i <= nums.size(); i++)
            xor00 ^= i;
        
        int k = (int)(log2(xor00));
        int rightmostbit = 1 << k;
 
    
     //   int rightmostbit = xor00 & ~(xor00 - 1);
        
        //cout << rightmostbit << endl;
        
        for (int n: nums) {
            if ((n & rightmostbit) != 0)
                xor1 ^= n;
            else
                xor0 ^= n;
        }
        
        //cout << xor1 << ' ' << xor0 << endl;
        
        for (int i = 1; i <= nums.size(); i++) {
            if ((i & rightmostbit) != 0)
                xor1 ^= i;
            else
                xor0 ^= i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == xor0)
                return {xor0, xor1};
        }
        
        return {xor1, xor0};
    }
};