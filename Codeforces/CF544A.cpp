#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,done;
	string s;
	cin>>k;
	cin>>s;
	n=s.length();
	map<char,int> alreadyOccured;
	vector<vector<int>> v;
	v.push_back({0});
	done=0;
	++alreadyOccured[s[0]];
	for (int i=1;i<n;++i)
	{
		++alreadyOccured[s[i]];
		if (alreadyOccured[s[i]]==1)
		{
			v[done].push_back(i-v[done][0]);
			++done;
			v.push_back({i});
		}
	}
	if (done+1<k)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for (int i=0;i<k-1;++i)
	{
		cout<<s.substr(v[i][0],v[i][1])<<"\n";
	}
	cout<<s.substr(v[k-1][0]);
	return 0;
}