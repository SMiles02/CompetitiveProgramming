#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solveSmol()
{
    int n,q,l,r;
    cin>>n>>q;
    vector<int> v(n+2,0);
    while (q--)
    {
        cin>>l>>r;
        ++v[l];
        --v[r+1];
    }
    for (int i=1;i<=n;++i)
    {
        v[i]+=v[i-1];
        if (v[i])
            cout<<i<<" ";
        else
            cout<<"1 ";
    }
    cout<<"\n";
}

void solveBig()
{
    int n,q,c,d;
    cin>>n>>q;
    vector<int> ans(n+1,n);
    vector<array<int,2>> v(q);
    for (int i=0;i<q;++i)
        cin>>v[i][0]>>v[i][1];
    sort(v.begin(), v.end());
    for (c=0;c<q;++c)
    {
        for (d=c;d<q&&v[d][0]<=v[c][1];++d)
            v[c][1]=max(v[c][1],v[d][1]);
        --d;
        for (int i=v[c][0];i<=v[c][1];++i)
            ans[i]=v[c][0]+v[c][1]-i;
        c=d;
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,p;
    cin>>n>>p;
    if (p==0)
        while (n--)
            solveSmol();
    else
        while (n--)
            solveBig();
    return 0;
}