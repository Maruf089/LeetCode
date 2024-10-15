// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    long minEatingSpeed(vector<int>& piles, int h) {
        long ans = INT_MAX;
        long low = 1 , high = 1000000000;
        while(low <= high)
        {
            long mid = (low + high)/2;
            long sum = 0 ;
            for(auto it : piles)
            {
                sum += (it / mid) + (it % mid == 0 ? 0 : 1);
            }
            if(sum <= h)
              ans = min(ans , mid) , high = mid - 1;
            else low = mid + 1;
            
        }
        return ans;
        
    }
};