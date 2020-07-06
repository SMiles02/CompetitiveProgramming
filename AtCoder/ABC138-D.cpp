#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,q,a,b,currentAdd;
map<int,vector<int>> children;
map<int,int> counter;
map<int,int> answers;

void builder(int cur)
{
	int s=children[cur].size();
	currentAdd+=counter[cur];
	answers[cur]=currentAdd;
	//cout<<"Vertice "<<cur<<", has a counter of "<<currentAdd<<"\n";
	for (int i=0;i<s;++i)
	{
		builder(children[cur][i]);
	}
	currentAdd-=counter[cur];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	currentAdd=0;
	cin>>n>>q;
	for (int i=1;i<n;++i)
	{
		cin>>a>>b;
		children[a].push_back(b);
	}
	while (q--)
	{
		cin>>a>>b;
		counter[a]+=b;
	}
	builder(1);
	for (int i=1;i<=n;++i)
	{
		cout<<answers[i]<<" ";
	}
	return 0;
}