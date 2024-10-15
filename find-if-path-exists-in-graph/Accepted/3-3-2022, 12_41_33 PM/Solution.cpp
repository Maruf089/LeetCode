// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>graph[300000];
        for(auto it : edges)
        {
            vector<int>vc = it;
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
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
            
            for(auto it : graph[des])
            {
                int to = it;
           
                 if( visit[to] == false )
                 {
                    visit[to] = true;
                    Q.push(to);
                 }
               
            }
         }
                                     
        if(ans==-1) return false;
        else return true;
        
    }
};