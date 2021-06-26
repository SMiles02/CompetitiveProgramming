#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,p,q,cur=0;
	string s;
	cin>>n>>p>>q;
	cin>>s;
	for (int i=0;i<101;++i)
	{
		for (int j=0;j<101;++j)
		{
			if (p*i+q*j==n)
			{
				cout<<i+j<<"\n";
				for (int k=0;k<i;++k)
				{
					for (int l=0;l<p;++l)
					{
						cout<<s[cur];
						++cur;
					}
					cout<<"\n";
				}
				for (int k=0;k<j;++k)
				{
					for (int l=0;l<q;++l)
					{
						cout<<s[cur];
						++cur;
					}
					cout<<"\n";
				}
				return 0;
			}
		}
	}
	cout<<-1;
	return 0;
}