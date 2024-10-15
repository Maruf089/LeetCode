// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& vc) 
    {
        int n = vc.size();
        bool ase = false;
        int min1 = INT_MAX , min2 = INT_MAX;
    
        for(int i = 0 ; i < n ; i++)
        {
            
            if( vc[i] > min1 and vc[i] > min2)
                  ase = true;
            
            if( vc[i] < min1 )
            {
                min2 = min1;
                min1 = vc[i];
            }
            else if( vc[i] < min2 )
                min2 = vc[i];
                
            
        }
        
        return ase;
        
    }
};