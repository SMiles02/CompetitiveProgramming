#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,a,b,notDone=1;
	vector<pair<int,int>> v;
	map<int,int> occurences;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>k;
		++occurences[k];
		v.push_back(make_pair(k,i+1));	
	}
	sort(v.begin(),v.end());
	vector<int> two;
	vector<int> more;
	for (int i=1;i<2001;++i)
	{
		if (occurences[i]==2)
		{
			two.push_back(i);
		}
		else if (occurences[i]>2)
		{
			more.push_back(i);
		}
	}
	vector<int> x;
	vector<int> y;
	vector<int> z;
	if (sz(more)==0&&sz(two)<2)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	if (sz(more)>0)
	{
		a=more[0];
		for (int i=0;i<n;++i)
		{
			if (notDone)
			{
				if (v[i].first==a)
				{
					notDone=0;
					x.push_back(v[i].second);
					x.push_back(v[i+1].second);
					x.push_back(v[i+2].second);
					y.push_back(v[i+1].second);
					y.push_back(v[i].second);
					y.push_back(v[i+2].second);
					z.push_back(v[i+2].second);
					z.push_back(v[i+1].second);
					z.push_back(v[i].second);
					i+=2;
				}
				else
				{
					x.push_back(v[i].second);
					y.push_back(v[i].second);
					z.push_back(v[i].second);
				}
			}
			else
			{
				x.push_back(v[i].second);
				y.push_back(v[i].second);
				z.push_back(v[i].second);
			}
		}
	}
	else
	{
		a=two[0];
		b=two[1];
		for (int i=0;i<n;++i)
		{
			if (v[i].first==a)
			{
				//cout<<"i: "<<i<<", "<<v[i].second<<" "<<v[i+1].second<<"\n";
				x.push_back(v[i].second);
				x.push_back(v[i+1].second);
				y.push_back(v[i+1].second);
				y.push_back(v[i].second);
				z.push_back(v[i].second);
				z.push_back(v[i+1].second);
				i+=1;
			}
			else if (v[i].first==b)
			{
				//cout<<"i: "<<i<<", "<<v[i].second<<" "<<v[i+1].second<<"\n";
				x.push_back(v[i].second);
				x.push_back(v[i+1].second);
				y.push_back(v[i+1].second);
				y.push_back(v[i].second);
				z.push_back(v[i+1].second);
				z.push_back(v[i].second);
				i+=1;
			}
			else
			{
				//cout<<"i: "<<i<<", "<<v[i].second<<"\n";
				x.push_back(v[i].second);
				y.push_back(v[i].second);
				z.push_back(v[i].second);
			}
		}
	}
	for (int i=0;i<n;++i)
	{
		cout<<x[i]<<" ";
	}
	cout<<"\n";
	for (int i=0;i<n;++i)
	{
		cout<<y[i]<<" ";
	}
	cout<<"\n";
	for (int i=0;i<n;++i)
	{
		cout<<z[i]<<" ";
	}
	return 0;
}