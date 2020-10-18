#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size();
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int MAXN=3e5+7;
int n,k,x,y,ans,INF=1e9,cur;
set<int> typesF[MAXN];
set<int,greater<int>> typesB[MAXN];

ll solve()
{
	ans=0;
	cin>>x>>y;
	for (int i=1;i<=k;++i)	
	{
		cur=INF;
		if (typesF[i].lower_bound(x)!=typesF[i].end())
			cur=(*(typesF[i].lower_bound(x)))-x;
		if (typesB[i].lower_bound(x)!=typesB[i].end())
			cur=min(cur,x-(*(typesB[i].lower_bound(x))));
		ans=max(ans,cur);
	}
	if (ans==INF)
		return -1;
	return ans;
}

int main()
{
	int q,x_i,t_i,a_i,b_i;
	cin>>n>>k>>q;
	for (int i=0;i<n;++i)
	{
		cin>>x_i>>t_i>>a_i>>b_i;
		typesF[t_i].insert(x_i);
		typesB[t_i].insert(x_i);
	}
	while (q--)
		cout<<solve()<<"\n";
}