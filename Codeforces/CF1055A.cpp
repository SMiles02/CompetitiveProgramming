#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s;
    cin>>n>>s;
    int a[n+1],b[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    if (a[1]==0)
    {
        cout<<"NO";
        return 0;
    }
    if (a[s])
    {
        cout<<"YES";
        return 0;
    }
    for (int i=s+1;i<=n;++i)
        if (a[i]&&b[i]&&b[s])
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
    return 0;
}