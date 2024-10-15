// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Solution 1 using DFS

// class Solution {
// public:
    
//     void dfs(Node *node,Node *copy,vector<Node*>&vis)
//     {
//         vis[copy->val] = copy;
        
//         for(auto it : node->neighbors)
//         {
//             if(vis[it->val] == NULL)
//             {
//                 Node *Newnode = new Node(it->val);
//                 (copy->neighbors).push_back(Newnode);
//                 dfs(it,Newnode,vis);
//             }
//             else
//             {
//                  (copy->neighbors).push_back(vis[it->val]);
//             }
//         }
        
//     }
    
//     Node* cloneGraph(Node* node) {
        
//         if( node == NULL )
//             return NULL;
        
//         Node* copy = new Node(node->val);
        
        
//         vector<Node*>visited(1000,NULL);
        
//         dfs(node,copy,visited);
        
//         return copy;
        
//     }
// };


// Solution 2 Using BFS
class Solution {
    
    public:
    
    map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        
        Node* clone = new Node(node->val);
        mp[node] = clone;
        
        queue<Node*>Q;
        Q.push(node);
        
        while(Q.size())
        {
            auto curr = Q.front();
            Q.pop();
            
            for(auto it : curr->neighbors)
            {
                if( mp.find(it) != mp.end() )
                {
                    
                    (mp[curr]->neighbors).push_back(mp[it]);
                    
                }
                else
                {
                    mp[it] = new Node(it->val);
                    (mp[curr]->neighbors).push_back(mp[it]);
                    Q.push(it);
                    
                }
            }
        }
        
        return mp[node];
        
    }
    
};

