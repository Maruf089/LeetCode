// https://leetcode.com/problems/course-schedule

class Solution {
public:
    
    vector<int> adj[200000];
    vector<bool> visited;
    vector<int> parent;
    int cycle_start, cycle_end;
    
    bool dfs(int v, int par)   // passing vertex and its parent vertex
    {
    visited[v] = true;
    for (int u : adj[v])
    {
        if(u == par)
            continue; // skipping edge to parent vertex
        if (visited[u])
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
    
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;
        
    
        
    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1)
    {
        return true;
    }
    else return false;
        
    }
};