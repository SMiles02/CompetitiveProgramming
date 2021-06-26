#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,int> visited;
int i,n;
vector<int> v;

void path()
{
	int cur = i;
	visited[cur]=1;
	while (true)
	{
		if (visited[v[cur]-1])
		{
			cout<<v[cur]<<" ";
			break;
		}
		cur=v[cur]-1;
		visited[cur]=1;
	}
	visited.clear();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k;
	cin>>n;
	for (i=0;i<n;++i)
	{
		cin>>k;
		v.push_back(k);
	}
	for (i=0;i<n;++i)
	{
		path();
	}
	return 0;
}