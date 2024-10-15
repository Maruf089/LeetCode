// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
   int jump(vector<int>& nums) {
       
       if(nums.size()==1) return 0;
       
       int jumps = 0, curEnd = 0, curFarthest = 0;
       for(int i=0;i<nums.size()-1;i++)
       {
           curFarthest = max(curFarthest , i + nums[i]);
           if(i==curEnd)
           {
               jumps++;
               curEnd = curFarthest;
           }
       }
       return jumps;
       
   }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
/*    
public:
   int jump(vector<int>& nums) {
	vector<int> dp(size(nums), 10001);
	return solve(nums, dp, 0);
    }

    int solve(vector<int>& nums, vector<int>& dp, int pos) {
	if(pos >= size(nums) - 1) return 0;    
	if(dp[pos] != 10001) return dp[pos];    
	
	for(int j = 1; j <= nums[pos]; j++)
		dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));        
	return dp[pos];
    }
};
*/