// https://leetcode.com/problems/course-schedule-ii



class Solution {
public:
            
    vector<int>vc[200000+9];
vector<int>visited;
vector<int>ans;
bool cycle = false;

void dfs(int p)
{
    visited[p]=1;
    for(int aa : vc[p])
    {
        if(visited[aa]==1)
        {
            cycle = true;
            return;
        }
        else if(visited[aa]==0)
            dfs(aa);
    }

    visited[p]=2;
    ans.push_back(p);
    return ;
}



vector<int> findOrder(int n, vector<vector<int>>& prerequisites)
{


    for(auto it : prerequisites)
    {
        vc[it[0]].push_back(it[1]);
    }

    visited.assign(n+9, 0);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
        if(cycle)
            break;
    }
    if(cycle)
    {
        ans.clear();
        return ans;
    }
    else
    {
       // reverse(ans.begin(), ans.end());
        return ans;
    }

}

    

};