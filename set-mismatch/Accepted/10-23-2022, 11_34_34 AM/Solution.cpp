// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1])swap(nums[i], nums[nums[i] - 1]);
        }
        
        vector<int>vc;
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1)
            {
                
              vc.push_back(nums[i]);
              vc.push_back(i + 1);
                
            }
        }
        return vc;
    }
};