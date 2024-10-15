// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1) return {0}; 
        
        vector<int>vc[n];
        vector<int>in(n , 0 );
        
        for(auto it : edges)
        {
            vc[it[0]].push_back(it[1]);
            vc[it[1]].push_back(it[0]);
            
            in[it[0]]++;
            in[it[1]]++;
        }
        
        queue<int>Q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==1) Q.push(i);
        }
        
        vector<int>res;
        while(n > 2)  /// bcz at most 2 answer possible
        {
            int sz = Q.size();
            n -= Q.size();
            while(sz--)
            {
                int u = Q.front();
                Q.pop();
                
                for(auto v : vc[u])
                {
                    in[v]--;
                    if(in[v]==1)
                    {
                        Q.push(v);
                    }
                }
            }
            
        }
        
        while(Q.size())
        {
            res.push_back(Q.front());
            Q.pop();
        }
        
        
        return res;
        
    }
};