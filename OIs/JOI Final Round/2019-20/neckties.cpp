#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    array<int,2> a[n+1];
    int b[n],ans[n+1];
    vector<int> p(n+1,0),s(n+1,0);
    for (int i=0;i<n+1;++i)
        cin>>a[i][0], a[i][1]=i;
    for (int i=0;i<n;++i)
        cin>>b[i];
    sort(a,a+n+1);
    sort(b,b+n);
    for (int i=0;i<n;++i)
    {
        p[i] = max(a[i+1][0]-b[i],0);
        s[i+1] = max(a[i][0]-b[i],0);
    }
    for (int i=n-1;i>=0;--i)
        p[i]=max(p[i],p[i+1]);
    for (int i=1;i<=n;++i)
        s[i]=max(s[i],s[i-1]);
    for (int i=0;i<=n;++i)
        ans[a[i][1]]=max(p[i],s[i]);
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}