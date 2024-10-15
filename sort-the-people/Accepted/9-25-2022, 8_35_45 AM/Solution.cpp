// https://leetcode.com/problems/sort-the-people

class Solution {
public:
    
    
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        
        vector< pair<int,  string > > vc;
        vector<string > res;
        
        for(int i = 0 ; i <  names.size() ; i++)
            vc.push_back({h[i] , names[i]});
        sort(vc.begin() , vc.end());
        
        for(int i = vc.size() - 1 ; i >= 0 ; i--)
            res.push_back(vc[i].second);
        return res;
            
        
    }
};