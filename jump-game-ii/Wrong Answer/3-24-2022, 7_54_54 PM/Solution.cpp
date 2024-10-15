// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()==1) return 0;
    //    if(nums[0] >= nums.size()) return 1;
        
        int x = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(x + nums[i] >= nums.size())
                return i+1;
            x = max(x , x + nums[i] );
        }
        return nums.size();
        
    }
};