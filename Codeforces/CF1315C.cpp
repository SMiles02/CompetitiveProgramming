#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,cur;
    cin>>n;
    int b[n];
    int a[2*n];
    map<int,int> m;
    map<int,int> occupied;
    for (int i=0;i<n;++i)
    {
        cin>>b[i];
        a[2*i]=b[i];
        m[b[i]]=1;
    }
    for (int i=0;i<n;++i)
    {
        cur=b[i]+1;
        while (m[cur])
        {
            ++cur;
        }
        if (cur>2*n)
        {
            cout<<"-1\n";
            return;
        }
        m[cur]=1;
        a[2*i+1]=cur;
    }
    for (int i=0;i<n;++i)
    {
        cout<<a[2*i]<<" "<<a[2*i+1]<<" ";
    }
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}