// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& vc) 
    {
        int n = vc.size();
        bool ase = false;
        int min1 = INT_MAX , min2 = INT_MAX , prev = -1;
    
        for(int i = 0 ; i < n ; i++)
        {
            
            if( vc[i] <= min1 )
            {
                min1 = vc[i];
            }
            else if( vc[i] <= min2 )
                min2 = vc[i];
            else 
                ase = true;
                
            
        }
        
        return ase;
        
    }
};