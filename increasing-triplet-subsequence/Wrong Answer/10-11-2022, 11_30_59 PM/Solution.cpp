// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& vc) 
    {
        int n = vc.size();
        int arr[n+9];
        for(int i = 0 ;i < n + 9 ; i++)
            arr[i] = 0;
        
        stack<int>st;
        st.push(0);
    
        for(int i = 0 ; i < n ; i++)
        {
            
            if(st.size()==0)
            {
                st.push(i);
                continue;
            }
            
            while(st.size() and vc[i] > vc[st.top()])
            {
                arr[ st.top() ] = i;
                st.pop();
            }
            
            st.push(i);
            
        }
        
        while (st.size()) {
          arr[ st.top() ] = -1 ;
          st.pop();
        }
        
        
        bool ase = false;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i]!=-1)
            {
                if(arr[ arr[i] ] != -1)
                    ase = true;
            }
        }
        
        return ase;
        
    }
};