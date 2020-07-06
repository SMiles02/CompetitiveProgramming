#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q,n;
	bool isTrue;
	cin>>q;
	while (q--)
	{
		cin>>n;
		int a[n];
		for (int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		if (n==1)
		{
			cout<<"YES\n";
		}
		else
		{
			isTrue=false;
			for (int i=0;i<n;++i)
			{
				if (i==n-1)
				{
					isTrue=true;
				}
				else if (a[i]==n)
				{
					if (a[i+1]!=1)
					{
						break;
					}
				}
				else
				{
					if (a[i]+1!=a[i+1])
					{
						break;
					}
				}
			}
			for (int i=n-1;i>-1;--i)
			{
				if (i==0)
				{
					isTrue=true;
				}
				else if (a[i]==n)
				{
					if (a[i-1]!=1)
					{
						break;
					}
				}
				else
				{
					if (a[i]+1!=a[i-1])
					{
						break;
					}
				}
			}
			if (isTrue)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}