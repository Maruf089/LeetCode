// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

class Solution {
public:
    int longestSubarray(vector<int>& vc) {

	int Max = 0 ;
	for (auto it : vc)
	{
		Max = max(Max , it);
	}
	vector<int>pos;

	int len = 0;
	for (int i = 0 ; i < vc.size() ; i++)
	{
		if (vc[i] == Max) pos.push_back(i + 1);
		else
		{
			bool ok = true;
			for (int j = 0 ; j < 32 ; j++)
			{
				if ( (Max & (1 << j)) != (vc[i] & (1 << j)) )
					ok = false;
			}
			if (ok)
				pos.push_back(i + 1);
		}
	}

	

	int prev = 0 , cont = 0;
	for (int i = 0 ; i < pos.size() ; i++)
	{
		if ( (pos[i] - 1) == prev )
		{
			cont++;
			prev = pos[i];
		}
		else
		{
			len = max(len , cont);
            prev = pos[i];
			cont = 1;
		}
	}
	len = max(len , cont);


	return len;

}
};