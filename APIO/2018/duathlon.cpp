#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN = 1e5 + 7;
vector<int> edges[MAXN];
bool done[MAXN],ok;
ll ans,cur;

void dfs(int c)
{
	done[c]=1;
	++cur;
	if (sz(edges[c])<2)
		ok=0;
	for (int i : edges[c])
		if (!done[i])
			dfs(i);
}

int main()
{
	int n,m,u,v;
	cin>>n>>m;
	while (m--)
	{
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for (int i=1;i<=n;++i)
		if (!done[i])
		{
			cur=0;
			ok=1;
			dfs(i);
			if (ok)
				ans+=((cur)*(cur-1)*(cur-2));
			else
				ans+=(((cur)*(cur-1)*(cur-2))/3);
		}
	cout<<ans;
}