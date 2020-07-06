#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,maxDepth=0,curDepth=0;
map<int,vector<int>> m;

void searcher(int cur)
{
    //cout<<cur<<" "<<curDepth<<" !\n";
    maxDepth=max(maxDepth,curDepth);
    ++curDepth;
    for (int i=0;i<sz(m[cur]);++i)
    {
        searcher(m[cur][i]);
    }
    --curDepth;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        m[k].push_back(i);
    }
    searcher(-1);
    cout<<maxDepth;
    return 0;
}