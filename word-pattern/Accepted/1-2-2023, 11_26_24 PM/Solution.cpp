// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>s;
        string st="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                s.push_back(st);
                st="";
                
            }
            else
                st+=str[i];
        }
        if(st!="")
            s.push_back(st);
        if(pattern.size()!=s.size())
            return false;
        map<string,vector<int> > ms;
        map<char,vector<int> > mt;
         for(int i=0;i<s.size();i++)
        {
            ms[s[i]].push_back(i);
            mt[pattern[i]].push_back(i);
            
        }
        for(int i=0;i<s.size();i++)
        {
            if(ms[s[i]]!=mt[pattern[i]])return false;
        }
        return true;
    }
};