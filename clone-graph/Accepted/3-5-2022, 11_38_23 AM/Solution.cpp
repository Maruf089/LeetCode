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

class Solution {
public:
    
    void dfs(Node *node,Node *copy,vector<Node*>&vis)
    {
        vis[copy->val] = copy;
        
        for(auto it : node->neighbors)
        {
            if(vis[it->val] == NULL)
            {
                Node *Newnode = new Node(it->val);
                (copy->neighbors).push_back(Newnode);
                dfs(it,Newnode,vis);
            }
            else
            {
                 (copy->neighbors).push_back(vis[it->val]);
            }
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        
        if( node == NULL )
            return NULL;
        
        Node* copy = new Node(node->val);
        
        
        vector<Node*>visited(1000,NULL);
        
        dfs(node,copy,visited);
        
        return copy;
        
    }
};