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
	int n,k,a;
	ll ans=0;
	cin>>n;
	map<int,int> numberOfOnes;
	while (n--)
	{
		cin>>k;
		a=0;
		while (k>0)
		{
			a+=k%2;
			k/=2;
		}
		++numberOfOnes[a];
	}
	for (int i=0;i<35;++i)
	{
		if (numberOfOnes[i]>=2)
		{
			ans+=NCR(numberOfOnes[i],2);
		}
	}
	cout<<ans;
	return 0;
}