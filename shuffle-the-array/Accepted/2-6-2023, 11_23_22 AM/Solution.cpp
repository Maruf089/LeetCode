// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int idx1 = 0 , idx2 = n;
        vector<int>vc;
        for(int i = 0 ; i<n;i++)
        {
            vc.push_back(nums[i]);
            vc.push_back(nums[idx2]);
            idx2++;
        }
        return vc;
        
    }
};