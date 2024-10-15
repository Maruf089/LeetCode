// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()==1) return 0;
        int x = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(x + nums[i] >= nums.size())
                return i+1;
            x = max(x , x + nums[i] );
        }
        return nums.size();
        
    }
};