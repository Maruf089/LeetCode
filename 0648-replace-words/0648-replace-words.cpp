class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,int>mp;
        for(auto it : dictionary)
            mp[it]++;
        string s = "", Final = "";
        vector<string>vc;
        for(auto it : sentence){
            if(it==' '){
                 vc.push_back(s);
                s = "";
            }
            else {
                s += it;
            } 
        }
        vc.push_back(s);
        
        
        for(int j = 0 ; j < vc.size();j++){
            s = "";
            for(int i = 0 ; i < vc[j].size();i++){
                s += vc[j][i];
                if(mp[s]){
                    break;
                }
            }
            if(j== vc.size()-1)
            Final += s;
            else Final += (s + " ");
        }
        return Final;
        
    }
};