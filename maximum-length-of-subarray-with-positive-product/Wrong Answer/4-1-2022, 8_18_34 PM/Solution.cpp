// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    #define f0(i,b) for(int i=0;i<(b);i++)
    #define f1(i,b) for(int i=1;i<=(b);i++)
    #define ll long long int
    #define pb push_back
    #define sz size()
    #define all(v) v.begin(),v.end()
    int getMaxLen(vector<int>& nums) {
        
        vector<ll>vc , zero , minus;
        int n = nums.size();
        ll l,r;
		f0(i, n)
		{
			ll a = nums[i];
			vc.pb(a);
			if (a < 0) minus.pb(i + 1);
		}
		vector<ll>minus_cum(n + 11), two(n + 11), cnt(n + 11);


		zero.pb(0);
		f0(i, n)
		{

			if ( abs(vc[i]) == 2) two[i + 1] = 1;
			if (vc[i] == 0) zero.pb(i + 1);
			if (vc[i] < 0) minus_cum[i + 1] = 1;
		}
		zero.pb(n + 1);

		f1(i, n + 9)
		{
			two[i] += two[i - 1] ;
			minus_cum[i] += minus_cum[i - 1];
		}

		ll Max = -1;
		for (int i = 0; i < zero.sz; i++)
		{
			if (i + 1 < zero.sz )
			{
				int prev = zero[i] , now = zero[i + 1];

				int minus_ase = (minus_cum[now] - minus_cum[prev]);

				if ( minus_ase % 2 == 0 )
				{
					ll two_ase = two[now] - two[prev];
					if (two_ase > Max)
					{
						l = prev;
						r = now;
						Max = two_ase;
					}
				}
				else
				{
					int pos1 = upper_bound(all(minus), prev) - minus.begin();
					int pos2 = upper_bound(all(minus), now) - minus.begin();
					pos2--;

					/// samner minus
					ll two_ase = two[now] - two[ minus[pos1]];
					if (two_ase > Max)
					{
						l = minus[pos1];
						r = now;
						Max = two_ase;
					}

					two_ase = two[minus[pos2] - 1] - two[prev];
					if (two_ase > Max)
					{
						l = prev;
						r = minus[pos2];
						Max = two_ase;
					}

				}
			}
		}

		return n - (l << ' ' << max(0LL , n - 1LL * r + 1LL) ) ;
    }
};