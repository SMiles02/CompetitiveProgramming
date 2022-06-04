#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,l,r,x,smallest,biggest,currentIndice,total,ans=0;
vector<int> all;

void allPossibilities()
{
	int lastBiggest;
	if (currentIndice==n)
	{
		if (total>=l)
		{
			if (total<=r)
			{
				if (biggest-smallest>=x)
				{
					//cout<<"total - "<<total<<", smallest - "<<smallest<<", biggest - "<<biggest<<"\n";
					++ans;
				}
			}
		}
	}
	else
	{
		++currentIndice;
		allPossibilities();
		lastBiggest=biggest;
		biggest=all[currentIndice-1];
		total+=biggest;
		allPossibilities();
		total-=biggest;
		biggest=lastBiggest;
		--currentIndice;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>l>>r>>x;
	int k;
	for (int i=0;i<n;++i)
	{
		cin>>k;
		all.push_back(k);
	}
	sort(all.begin(),all.end());
	for (int i=0;i<n;++i)
	{
		currentIndice=i+1;
		smallest=all[i];
		biggest=all[i];
		total=all[i];
		allPossibilities();
	}
	cout<<ans;
	return 0;
}