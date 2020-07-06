#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll minN(ll a, ll b)
{
	if (a<b)
	{
		return a;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll ans,det,cur,a,b;
	int t,n,x,done,maxE;
	cin>>t;
	vector<vector<ll>> v;
	vector<ll> z;
	while (t--)
	{
		cin>>n>>x;
		done=0;
		maxE=0;
		for (int i=0;i<n;++i)
		{
			cin>>a>>b;
			z.push_back(a);
			z.push_back(b);
			v.push_back(z);
			z.clear();
			if (v[i][0]>maxE)
			{
				maxE=v[i][0];
			}
		}
		//cout<<"maxE = "<<maxE<<"\n";
		if (maxE>=x)
		{
			cout<<1;
		}
		else
		{
			for (int i=0;i<n;++i)
			{
				if (v[i][0]>v[i][1])
				{
					det=v[i][0]-v[i][1];
					if ((x-maxE)%det)
					{
						cur=((x-maxE)/det)+1;
					}
					else
					{
						cur=(x-maxE)/det;
					}
					if ((cur*det)-v[i][1]>=x)
					{
						--cur;
					}
					++cur;
					if (done)
					{
						ans=minN(ans,cur);
					}
					else
					{
						ans=cur;
						done=1;
					}
					//cout<<"case "<<t<<", number = "<<i<<", cur = "<<cur<<", ans = "<<ans<<"\n";
				}
			}
			if (done)
			{
				cout<<ans;
			}
			else
			{
				cout<<-1;
			}
		}
		cout<<"\n";
		v.clear();
	}
	return 0;
}