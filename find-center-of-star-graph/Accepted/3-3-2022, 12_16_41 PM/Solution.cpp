// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int,int>outdeg;
        int ans = -1;
        for(auto it : edges)
        {
            vector<int>vc = it;
            outdeg[vc[0]]++;
            outdeg[vc[1]]++;
            
            if(outdeg[vc[0]] > 1)
            {
                ans = vc[0];
                break;
            }
            
            if(outdeg[vc[1]] > 1)
            {
                ans = vc[1];
                break;
            }
            
        }
        
        return ans;
        
        
        
         
    }
};