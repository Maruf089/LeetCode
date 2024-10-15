// https://leetcode.com/problems/simplify-path

public class Solution {
    public string SimplifyPath(string path) {
        
        var folders = path.Split('/');
        Stack<string> stack = new Stack<string>();
        
        
        foreach(var fol in folders)
        {
           if(fol == ".."){
                if(stack.Count > 0){
                    stack.Pop();
                    
                }
                continue;
            }
            else if(fol == "." || fol == "") continue;
            
            stack.Push(fol);
                
        }
        
        
        var result = "";
        
        while(stack.Count > 0){
            var folder =  stack.Pop();
            
            result = "/"+folder + result;
            
        }
        
        return result == "" ? "/" : result ;
        
    }
}