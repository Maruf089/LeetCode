// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        
        int max_ase = nums[0] , cur_max = 0, min_ase = nums[0] , cur_min = 0 , total = 0 ;
        for(int i=0;i<nums.size();i++)
        {
            cur_max = max(cur_max , cur_max + nums[i] );
            max_ase = max(max_ase , cur_max);
            
            cur_min = min(cur_min , cur_min + nums[i]);
            min_ase = min(min_ase , cur_min);
            
            total += nums[i];
        }
        
        
        return max(max_ase, total - min_ase );
     
        
    }
};