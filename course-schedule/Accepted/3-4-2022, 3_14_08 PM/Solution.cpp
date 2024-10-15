// https://leetcode.com/problems/course-schedule

class Solution {
public:
    
    vector<int> adj[200000];
    vector<char> color;
    vector<int> parent;
    int cycle_start, cycle_end;

    bool dfs(int v)
    {
        color[v] = 1;
        for (int u : adj[v])
        {
            if (color[u] == 0)
            {
                parent[u] = v;
                if (dfs(u))
                    return true;
            }
            else if (color[u] == 1)
            {
                 cycle_end = v;
                 cycle_start = u;
                 return true;
            }
        }
        color[v] = 2;
        return false;
    }
    
    
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
    
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        color.assign(n, 0);
        parent.assign(n, -1);
        cycle_start = -1;
    
        for (int v = 0; v < n; v++)
        {
            if (color[v] == 0 && dfs(v))
                 break;
        }

        if (cycle_start == -1)  return true;
        else return false;
        
    }
};