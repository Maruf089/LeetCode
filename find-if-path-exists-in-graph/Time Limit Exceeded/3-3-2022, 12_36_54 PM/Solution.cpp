// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        queue<int>Q;
        vector<int>visit(300000,0);
        Q.push(source);
        int ans = -1;
        while(Q.size() > 0)
        {
            int des = Q.front();
            Q.pop();
            if(des==destination)
            {
                ans = 1;
                break;
            }
            
            for(auto it : edges)
            {
                vector<int>vc = it;
                if( (vc[0]==des or vc[1]==des) )
                {
                    if(des==vc[0])
                    {
                        if(visit[vc[1]]==false)
                        {
                            Q.push(vc[1]);
                            visit[vc[1]] = true;
                            
                        }
                    }
                    if(des==vc[1])
                    {
                        if( visit[vc[0]] == false )
                        {
                            visit[vc[0]] = true;
                            Q.push(vc[0]);
                        }
                        
                    }
                                      
                    
                }
               
            }
         }
                                     
        if(ans==-1) return false;
        else return true;
        
    }
};