#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,str,intelli,exp,maxi,mini;
	cin>>n;
	while (n--)
	{
		cin>>str>>intelli>>exp;
		if (str==intelli)
		{
			cout<<(exp+1)/2;
		}
		else
		{
			maxi=str+exp;
			mini=max(((str+intelli+exp)/2)+1,str);
			//cout<<"maxi: "<<maxi<<", mini: "<<mini<<", ";
			if (mini>maxi)
			{
				cout<<0;
			}
			else
			{
				cout<<maxi-mini+1;
			}
		}
		cout<<"\n";
	}
	return 0;
}