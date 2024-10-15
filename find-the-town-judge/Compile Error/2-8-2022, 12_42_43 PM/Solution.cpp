// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& vc) {
        
        map<int,int>indeg, outdeg;
        
        
        for(auto it : vc)
        {
            outdeg[it[0]]++;
            indeg[it[1]]++;
        }
        
        int judge = -1;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==n-1 and outdeg==0 )
                judge = i;
        }
        
        return judge;
      
        
    }
};