// https://leetcode.com/problems/divide-array-into-equal-pairs

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        bool f = true;
        map<int,int>mp;
        
        for(auto it : nums)
        {
            mp[it]++;
        }
        
        for(auto it : mp)
        {
            if(it.second % 2 == 1)
                f = false;
        }
        
        if(f) return true;
        else return false;
        
    }
};