#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+7, INF = 1e9;
int k, ans = INF, dp[1000007], sub[N];
vector<array<int,2>> e[N];
bitset<N> b;
 
int subDfs(int c, int p)
{
	sub[c]=1;
	for (auto i : e[c])
		if (i[0]!=p&&!b[i[0]])
			sub[c]+=subDfs(i[0],c);
	return sub[c];
}
 
int findC(int c, int p, int t)
{
	for (auto i : e[c])
		if (i[0]!=p&&!b[i[0]]&&sub[i[0]]>t)
			return findC(i[0],c,t);
	return c;
}
 
void dfs(int c, int p, int h, int t, bool fill)
{
	if (h>k)
		return;
	if (fill)
		dp[h]=min(dp[h],t);
	else
		ans=min(ans,dp[k-h]+t);
	for (auto i : e[c])
		if (i[0]!=p&&!b[i[0]])
			dfs(i[0],c,h+i[1],t+1,fill);
}
 
void undo(int c, int p, int h)
{
	if (h>k)
		return;
	dp[h]=INF;
	for (auto i : e[c])
		if (i[0]!=p&&!b[i[0]])
			undo(i[0],c,h+i[1]);
}
 
void solve(int n)
{
	int c = findC(n,-1,subDfs(n,-1)/2);
	b[c]=1;
	for (auto i : e[c])
		if (!b[i[0]])
		{
			dfs(i[0],c,i[1],1,0);
			dfs(i[0],c,i[1],1,1);
		}
	for (auto i : e[c])
		if (!b[i[0]])
			undo(i[0],c,i[1]);
	for (auto i : e[c])
		if (!b[i[0]])
			solve(i[0]);
}
 
int best_path(int n, int K, int h[][2], int l[])
{
	k=K;
	for (int i=0;i<n-1;++i)
	{
		e[h[i][0]].push_back({h[i][1],l[i]});
		e[h[i][1]].push_back({h[i][0],l[i]});
	}
	for (int i=1;i<=k;++i)
		dp[i]=INF;
	solve(0);
	if (ans==INF)
		return -1;
	return ans;
}