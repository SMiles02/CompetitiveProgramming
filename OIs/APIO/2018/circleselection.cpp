#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int MAXN = 3e5 + 7;
int ans[MAXN];
map<int,set<pii>> m;
set<int> coOrds;
set<pair<pii,int>> se;

int main()
{
	int n,x,y,r,c;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>x>>y>>r;
		coOrds.insert(x);
		m[x].insert({r,i});
		se.insert({{x,r},-i});
	}
	while (sz(se))
	{
		x=(*(--se.end())).f.f;
		y=-(*(--se.end())).s;
		r=(*(--se.end())).f.s;
		cout<<x<<" "<<y<<" "<<r<<"\n";
		se.erase(--se.end());
		ans[y]=y;
		m[x].erase(m[x].find({r,y}));
		c=x-r;
		while (1)
		{
			if (coOrds.lower_bound(c)==coOrds.end())
				break;
			c=*(coOrds.lower_bound(c));
			if (c>x+r)
				break;
			for (auto i : m[c])
			{
				if (ans[i.s])
					continue;
				ans[i.s]=y;
				se.erase(se.find({{c,i.f},-i.s}));
			}
			m[c].clear();
			coOrds.erase(coOrds.find(c));
		}
	}
	for (int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
}