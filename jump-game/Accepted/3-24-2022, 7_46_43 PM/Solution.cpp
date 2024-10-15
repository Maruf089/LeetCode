// https://leetcode.com/problems/jump-game

class Solution {
public:
  
    bool canJump(vector<int>& nums) {
        
       int x = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(x < i) return false;
            x = max(x , i + nums[i]);
        }
        return true;
        
    }
};