// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_ase = nums[0] , cur_max = 0;
        for(int i=0;i<nums.size();i++)
        {
            cur_max = cur_max + nums[i];
            max_ase = max(max_ase , cur_max);
            if(cur_max < 0)
                cur_max = 0;
        }
        
        
        return max_ase;
        
    }
};