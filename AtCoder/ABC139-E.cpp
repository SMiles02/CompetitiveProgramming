#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans=0,done,left;
	cin>>n;
	left=(n)*(n-1);
	left/=2;
	int currentMatch[n]={0};
	int currentDay[n]={0};
	int a[n][n-1];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n-1;++j)
		{
			cin>>a[i][j];
		}
	}
	while (left)
	{
		++ans;
		done=0;
		for (int i=0;i<n;++i)
		{
			cout<<"currentMatch[i="<<i<<"] = "<<currentMatch[i]<<"\n";
			if (currentMatch[i]<n-1)
			{
				cout<<" currentDay[i="<<i<<"] = "<<currentDay[i]<<"\n";
				if (currentDay[i]<ans)
				{
					cout<<"  currentDay[a[i][currentMatch[i]]-1] = "<<currentDay[a[i][currentMatch[i]]-1]<<"\n";
					if (currentDay[a[i][currentMatch[i]]-1]<ans)
					{
						cout<<"   a[a[i][currentMatch[i]]-1][currentDay[a[i][currentMatch[i]]-1]] = "<<a[a[i][currentMatch[i]]-1][currentDay[a[i][currentMatch[i]]-1]]<<"\n";
						if (a[a[i][currentMatch[i]]-1][currentDay[a[i][currentMatch[i]]-1]]==i+1)
						{
							cout<<i<<" "<<a[i][currentMatch[i]]-1<<"\n";
							--left;
							++done;
							++currentMatch[a[i][currentMatch[i]]-1];
							currentDay[currentMatch[i]-1]=ans;
							currentDay[i]=ans;
							++currentMatch[i];
						}
					}
				}
			}
		}
		if (!done)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<ans;
	return 0;
}