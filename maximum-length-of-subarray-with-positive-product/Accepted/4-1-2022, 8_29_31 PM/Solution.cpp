// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int frame_start = -1 ,neg = 0, first_neg = -2 , len = 0;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            if(nums[i]==0)
            {
                frame_start = i;
                neg = 0;
                first_neg = -2; 
            }
            else
            {
                if(nums[i] < 0) neg++;
                if(first_neg==-2 and neg==1) first_neg = i;
                if(neg%2==0)
                {
                    len = max(len , i - frame_start);
                }
                else len = max(len , i - first_neg);
                
            }
        }
        return len;
        
    }
};