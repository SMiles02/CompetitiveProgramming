#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+7;
vector<int> d[N];
set<int> worked[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s=0;
    cin>>n;
    long long ans=0;
    int a[n];
    for (int i=0;i<n;++i)
    	cin>>a[i];
    for (int i=1;i<N;++i)
    	for (int j=i*2;j<N;j+=i)
    		d[j].push_back(i);
    for (int i=n-1;i>0;--i)
    {
    	s+=a[i];
    	for (int j : d[s])
    		if (worked[s-j].count(j))
    		{
    			++ans;
    			worked[s].insert(j);
			}
		++ans;
		worked[s].insert(s);
	}
	cout<<ans;
    return 0;
}