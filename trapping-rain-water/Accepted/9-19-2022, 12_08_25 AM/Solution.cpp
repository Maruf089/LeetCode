// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    
    int trap(vector<int>& h) {
    int l = 0, r = h.size()-1, level = 0, water = 0;
        int l_max = 0 , r_max = 0;
    while (l < r) {
            
           if(h[l] < h[r])
           {
               if(h[l] >= l_max) l_max = h[l];
               else water += (l_max - h[l]);
               l++;
           }
           else
           {
               if(h[r] < r_max)
                   water += (r_max - h[r]);
               else r_max = h[r];
               r--;
           }
        
        }
    
        
        return water;
    }

};