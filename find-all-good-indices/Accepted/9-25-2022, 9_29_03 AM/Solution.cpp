// https://leetcode.com/problems/find-all-good-indices

class Solution {
public:
    
    int decre[100009] , incre[100009];
vector<int> goodIndices(vector<int>& vc, int k) {

	int counT = 0 ;
	for (int i = 0 ; i < vc.size() ; i++)
	{
		int idx = i + 1 , cnt = 1 , prev = vc[i];
		while ( idx < vc.size() and vc[idx] <= prev )
		{
			prev = vc[idx];
			cnt++;
			idx++;
		}
		decre[i] = cnt;
		i = idx - 1;
	}
	for (int i = 0 ; i < vc.size() ; i++)
	{
		if (i == 0) ;
		else
		{
			decre[i] = max(decre[i - 1] - 1 , decre[i]);
		}

	}


	for (int i = vc.size() - 1 ; i >= 0 ; i--)
	{
		int idx = i - 1 , cnt = 1 , prev = vc[i];
		while ( idx >= 0 and vc[idx] <= prev )
		{
			prev = vc[idx];
			cnt++;
			idx--;
		}
		incre[i] = cnt;
		i = idx + 1;
	}
	for (int i = vc.size() - 1 ; i >= 0 ; i--)
	{
		if (i == vc.size() - 1) ;
		else
		{
			incre[i] = max(incre[i + 1] - 1 , incre[i]);
		}
	}


	vector<int>res;
	for (int i = 0 ; i < vc.size() ; i++)
	{
		int left_idx = i - k , rgt_idx = i + k;
		if (left_idx >= 0 and rgt_idx < vc.size())
		{
			int lft_counT = decre[left_idx];
			int rgt_counT = incre[rgt_idx];
			if (lft_counT >= k and rgt_counT >= k)
			{
				res.push_back(i);
			}
		}
	}

	return res;

}

    
};