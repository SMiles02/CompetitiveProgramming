#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int maxPages[100001];
int h[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,s;
    cin>>n>>x;
    for (int i=0;i<n;++i)
        cin>>h[i];
    for (int i=0;i<n;++i)
    {
        cin>>s;
        for (int j=x;j-h[i]>=0;--j)
            maxPages[j]=max(maxPages[j-h[i]]+s,maxPages[j]);
    }
    cout<<maxPages[x];
    return 0;
}