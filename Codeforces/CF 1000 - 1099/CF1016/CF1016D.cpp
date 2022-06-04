#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,cur=0,ruc=0;
    cin>>n>>m;
    int a[n];
    int b[m];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        cur^=a[i];
    }
    for (int i=0;i<m;++i)
    {
        cin>>b[i];
        ruc^=b[i];
    }
    if (ruc!=cur)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    cur=a[0];
    for (int i=1;i<m;++i) cur^=b[i];
    cout<<cur<<" ";
    for (int i=1;i<m;++i) cout<<b[i]<<" ";
    for (int i=1;i<n;++i)
    {
        cout<<"\n"<<a[i]<<" ";
        for (int j=1;j<m;++j) cout<<"0 ";
    }
    return 0;
}