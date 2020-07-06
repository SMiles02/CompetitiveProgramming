#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,changesMade,k;
	cin>>n;
	int a[n];
	map<int,int> occurences;
	map<int,int> skippedAlready;
	vector<int> unused;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		++occurences[a[i]];
	}
	for (int i=1;i<=n;++i)
	{
		if (!occurences[i])
		{
			unused.push_back(i);
		}
	}
	sort(unused.rbegin(),unused.rend());
	changesMade=unused.size();
	k=changesMade-1;
	for (int i=0;i<n;++i)
	{
		if (occurences[a[i]]>1)
		{
			if (unused[k]<a[i]||skippedAlready[a[i]]||occurences[a[i]]==1)
			{
				--occurences[a[i]];
				a[i]=unused[k];
				--k;
			}
			else
			{
				skippedAlready[a[i]]=1;
			}
		}
	}
	cout<<changesMade<<"\n";
	for (int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}