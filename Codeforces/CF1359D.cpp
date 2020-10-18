#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF=-1e9;
int ans=INF,n,a[100000],cur;

void solve(int k)
{
    cur=0;
    for (int i=0;i<n;++i)
    {
        if (a[i]>k)
            a[i]=INF;
        cur=max(cur,0)+a[i];
        ans=max(ans,cur-k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=30;i>=-30;--i)
        solve(i);
    cout<<ans;
    return 0;
}