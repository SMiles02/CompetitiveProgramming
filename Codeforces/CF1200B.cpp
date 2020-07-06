#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n,m,k,g;
	bool win;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		cin>>n>>m>>k;
		vector<int> h;
		for (int j=0;j<n;++j)
		{
			cin>>g;
			h.push_back(g);
		}
		win=true;
		for (int j=0;j<n-1;++j)
		{
			if (h[j+1]-k>h[j]+m)
			{
				win=false;
				break;
			}
			if (h[j+1]-k>=h[j])
			{
				m-=h[j+1]-k-h[j];
			}
			else if (h[j+1]-k<0)
			{
				m+=h[j];
			}
			else
			{
				m+=h[j]-h[j+1]+k;
			}
		}
		if (win)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
		h.clear();
	}
	return 0;
}