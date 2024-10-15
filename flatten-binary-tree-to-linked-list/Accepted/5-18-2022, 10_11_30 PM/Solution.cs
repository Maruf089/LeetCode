// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public void Flatten(TreeNode root) {
        if(root==null) return;
        
        var temp=new List<TreeNode>();
        DFS( root,temp);
        for(int i=1;i<temp.Count;i++)
        {
            root.left=null;
            root.right = temp[i];
            temp[i].left=null;
            root = root.right;
        }
        
    }
    public void DFS(TreeNode root,List<TreeNode> temp)
    {
        if(root==null) return;
        temp.Add(root);
        DFS(root.left,temp);
        DFS(root.right,temp);
        
        
    }
}