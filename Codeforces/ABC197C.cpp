#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,a[25],ans=(1<<30);

void rec(int i, int x, int y)
{
    if (i==n)
    {
        ans=min(ans,x^y);
        return;
    }
    rec(i+1,x,y|a[i]);
    rec(i+1,x^y,a[i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    rec(1,0,a[0]);
    cout<<ans;
    return 0;
}