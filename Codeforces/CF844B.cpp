#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll NCR(int n, int r)
{
    if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r); 
    ll res = 1; 
    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,zeroes;
	ll ans=0;
	cin>>n>>m;
	int a[n][m];
	for (int i=0;i<n;++i)
	{
		zeroes=0;
		for (int j=0;j<m;++j)
		{
			cin>>a[i][j];
			if (a[i][j]==0)
			{
				++zeroes;
			}
		}
		//cout<<"i = "<<i<<", zeroes = "<<zeroes<<"\n";
		for (int j=2;j<=zeroes;++j)
		{
			ans+=NCR(zeroes,j);
			//cout<<"NCR("<<zeroes<<","<<j<<") = "<<NCR(zeroes,j)<<"\n";
		}
		for (int j=2;j<=(m-zeroes);++j)
		{
			ans+=NCR(m-zeroes,j);
			//cout<<"NCR("<<m-zeroes<<","<<j<<") = "<<NCR(m-zeroes,j)<<"\n";
		}
	}
	for (int j=0;j<m;++j)
	{
		zeroes=0;
		for (int i=0;i<n;++i)
		{
			if (a[i][j]==0)
			{
				++zeroes;
			}
		}
		//cout<<"j = "<<j<<"\n";
		for (int j=1;j<=zeroes;++j)
		{
			ans+=NCR(zeroes,j);
			//cout<<"NCR("<<zeroes<<","<<j<<") = "<<NCR(zeroes,j)<<"\n";
		}
		for (int j=1;j<=(n-zeroes);++j)
		{
			ans+=NCR(n-zeroes,j);
			//cout<<"NCR("<<n-zeroes<<","<<j<<") = "<<NCR(n-zeroes,j)<<"\n";
		}
	}
	cout<<ans;
	return 0;
}