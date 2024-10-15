// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    vector<int>vc , cum;
    
    int trap(vector<int>& h) {
        
       
    vc.resize(h.size() + 9);
	cum.resize(h.size() + 9);

	stack<int>st;
	st.push(0);
	vc[0] = 0;
	int idx = 1;

	for (int i = 1; i < h.size(); i++)
	{
		if (st.size() == 0)
		{
			st.push(i);
			continue;
		}

		while (st.size() and h[st.top()] <= h[i])
		{
			vc[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}


	for (int i = 1; i <= h.size(); i++)
	{
		if (vc[i - 1] == 0)
			vc[i - 1] = -1;
		cum[i] = cum[i - 1] + h[i - 1];
	}


	int counT = 0;
	int i = 0 ;
	while (i < h.size())
	{
		int nxt = vc[i];
		if (vc[i] == -1)
		{
			i++;
			continue;
		}

	
		if ( (i + 1) == nxt )
		{
			i++;
			continue;
		}

		int diff = cum[nxt + 1] - cum[i];
		int cal = h[i] * (nxt - i + 1) ;
		int besi = h[nxt] - h[i];


		counT += ( cal - (diff - besi ) );

	

		i = nxt;
	}
        
        
        return counT;
        
        
    }
};