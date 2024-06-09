class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int arr[27][101] = {0};
        for(int i = 0; i < words.size() ; i++){
            for(int j = 0; j < words[i].size();j++){
               arr[words[i][j] - 'a'][i]++;
            }
        }
        int l = words.size();
        cout << l << endl;
        vector<string>vc;
        for(int i = 0; i < words[0].size() ; i++){
            int c = 1 ;
            for(int j = 0; j < l;j++){
                if(arr[words[0][i] - 'a'][j] > 0)
                    arr[words[0][i] - 'a'][j]--;
                else c = 0;
            }
            string s = "";
            s += words[0][i] ;
            if(c) vc.push_back(s);
        }
        
        return vc;
        
        
    }
};