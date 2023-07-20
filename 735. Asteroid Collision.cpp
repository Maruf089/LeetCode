class Solution {
public:
    vector<int> asteroidCollision(vector<int>& vc) {
        int n = vc.size();
        stack<int> stk;

        for(int i=0;i<n;i++)
        {
            if(vc[i]>=0) stk.push(vc[i]);
            else
            {
                int vanish_both = 0;
                while( stk.size()>0)
                {
                    if( stk.top()>=0 and vc[i]<0 and  abs(stk.top()) < abs(vc[i]))
                        stk.pop();
                    else if(stk.top()>=0 and vc[i]<0 and abs(stk.top()) == abs(vc[i]) )
                    {
                        stk.pop();
                        vanish_both = 1;
                        break;
                    }
                    else if(stk.top()<0 and vc[i]<0 )
                    {
                        stk.push(vc[i]);
                        break;
                    }
                    else break;
                }
                if(!vanish_both and stk.size()==0) stk.push(vc[i]);
            }
        }
       
        vector<int> ans(stk.size(), 0);
        int size = stk.size();
        while(!stk.empty()){
            ans[--size] = stk.top();
            stk.pop();
        }
        return ans;
        
    }
};