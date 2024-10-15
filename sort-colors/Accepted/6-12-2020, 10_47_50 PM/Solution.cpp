// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one= 0 , two = 0 , zero = 0 ;
        for(auto it : nums)
        {
            if(it==0)
            zero++;
            else if(it==1)
                one++;
            else two++;
        }
        for(int i= 0 ; i<nums.size();i++)
        {
            if(zero)
            {
            nums[i] = 0 ;
            zero--;}
            else if(one)
            {
               nums[i] = 1 ;
            one--;}
            else
            {
                nums[i] = 2 ;
                two--;
            }
    
        }
        
    }
};