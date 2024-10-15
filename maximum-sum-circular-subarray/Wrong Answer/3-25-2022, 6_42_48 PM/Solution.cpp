// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>vc = nums;
        for(auto it : vc)
            nums.push_back(it);
        
        int max_ase = nums[0] , cur_max = 0 , idx = -1;
        for(int i=0;i<nums.size();i++)
        {
            cur_max = cur_max + nums[i];
            if(cur_max >= max_ase and (idx+n-1) <= i )
            {
                max_ase = cur_max;
                idx = i;
            }
            if(cur_max < 0)
            {
                cur_max = 0;
                idx = -1;
            }
        }
        
        
        return max_ase;
     
        
    }
};