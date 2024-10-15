// https://leetcode.com/problems/valid-anagram

public class Solution {
    public bool IsAnagram(string s, string t) {
        
        char[] charX = s.ToCharArray();
        Array.Sort(charX);
        
        char[] charY = t.ToCharArray();
        Array.Sort(charY);
        
        
        
        string ss =  new string (s.OrderBy(c => c).ToArray());
        string tt =  new string (t.OrderBy(c => c).ToArray());
        
        return ss==tt ;
        
    }
}