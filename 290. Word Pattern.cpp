class Solution {
public
    bool wordPattern(string pattern, string str) {
        vectorstrings;
        string st=;
        for(int i=0;istr.size();i++)
        {
            if(str[i]==' ')
            {
                s.push_back(st);
                st=;
                
            }
            else
                st+=str[i];
        }
        if(st!=)
            s.push_back(st);
        if(pattern.size()!=s.size())
            return false;
        mapstring,vectorint  ms;
        mapchar,vectorint  mt;
         for(int i=0;is.size();i++)
        {
            ms[s[i]].push_back(i);
            mt[pattern[i]].push_back(i);
            
        }
        for(int i=0;is.size();i++)
        {
            if(ms[s[i]]!=mt[pattern[i]])return false;
        }
        return true;
    }
};