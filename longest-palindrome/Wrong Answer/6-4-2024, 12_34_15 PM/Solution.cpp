// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(auto c : s){
            mp[c]++;
        }
        int c = 0;
        for(auto it : mp){
            if(it.second % 2 == 0) c+=it.second;
        }
        
        for(auto it : mp){
            if(it.second % 2) {c++; break;}
        }
        return c;
        
    }
};