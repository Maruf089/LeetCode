// https://leetcode.com/problems/number-of-good-paths

class Solution {
public:
   
    
            vector<int>vc[100000];
int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

	for (auto it : edges)
	{
		vc[it[0]].push_back(it[1]);
		vc[it[1]].push_back(it[0]);
	}

	queue<int>Q;
	Q.push(0);
	unordered_map<int, int>mp, cnt , leaf;
	mp[0] = vals[0];
	leaf[0]++;

	while (Q.size())
	{
		auto P = Q.front();
		Q.pop();
		for (auto it : vc[P])
		{
			if (mp[it] == 0)
			{
				mp[it] = max(vals[it] , vals[P]);
				Q.push(it);
			}
		}

		if (vc[P].size() == 1)
			leaf[P]++;
	}


	for (auto it : mp)
	{
		
			cnt[it.second]++;
	}

	int counT = 0 ;
	for (auto it : cnt)
	{
		counT += ( it.second * (it.second - 1) ) / 2;
	}

	return counT + vals.size();

}

};