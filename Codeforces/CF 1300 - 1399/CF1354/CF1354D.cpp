#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,q;
int a[1000000];
int k[1000000];

bool check(int x)
{
	int cur=0;
	for (int i=0;i<n;++i)
		if (a[i]<=x)
			++cur;
	for (int i=0;i<q;++i)
	{
		if (k[i]>0&&k[i]<=x)
			++cur;
		if (k[i]<0&&-k[i]<=cur)
			--cur;
	}
	if (cur)
		return 1;
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    int l,r,m;
    for (int i=0;i<n;++i)
    	cin>>a[i];
    for (int i=0;i<q;++i)
    	cin>>k[i];
   	if (!check(1000000))
   	{
   		cout<<0;
   		return 0;
   	}
   	l=1;r=1000000;
   	while (l<r)
   	{
   		m=l+(r-l)/2;
   		if (check(m))
   			r=m;
   		else
   			l=m+1;
   	}
   	cout<<l;
    return 0;
}