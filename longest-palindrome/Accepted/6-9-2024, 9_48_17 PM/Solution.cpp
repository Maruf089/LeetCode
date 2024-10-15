// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(auto c : s){
            mp[c]++;
        }
        int c = 0, m = 0;
        for(auto it : mp){
            if(it.second % 2 == 0) c+=it.second;
            if(it.second % 2) {
                if(m==0){
                    c += it.second;
                    m = it.second;
                }
                else c += (it.second-1);
            }
        }
        
        
        return c;
        
    }
};