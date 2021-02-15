#include <bits/stdc++.h>
using namespace std;

int n,k,ans[1001];
vector<int> groups[1001];
bitset<1001> selected;

int makeQuery()
{
    int x=0;
    vector<int> w;
    for (int i=1;i<=n;++i)
        if (selected[i])
            w.push_back(i);
    cout<<"? "<<w.size();
    for (int i : w)
        cout<<" "<<i;
    cout<<endl;
    cin>>x;
    return x;
}

void solve()
{
    int x,mx,c,l,r,m;
    cin>>n>>k;
    int sol[k+1];
    for (int i=1;i<=k;++i)
    {
        cin>>x;
        groups[i].clear();
        for (int j=0;j<x;++j)
        {
            cin>>c;
            groups[i].push_back(c);
        }
    }
    for (int i=1;i<=n;++i)
        selected[i]=1;
    mx=makeQuery();
    l=1;r=k;
    while (l^r)
    {
        m=l+(r-l)/2;
        for (int i=1;i<=n;++i)
            selected[i]=1;
        for (int i=l;i<=m;++i)
            for (int j : groups[i])
                selected[j]=0;
        c=makeQuery();
        if (c==mx)
            l=m+1;
        else
            r=m;
    }
    for (int i=1;i<=n;++i)
        selected[i]=1;
    for (int i : groups[l])
        selected[i]=0;
    c=makeQuery();
    for (int i=1;i<=k;++i)
        if (i^l)
            sol[i]=mx;
    sol[l]=c;
    cout<<"!";
    for (int i=1;i<=k;++i)
        cout<<" "<<sol[i];
    cout<<endl;
    string s;
    cin>>s;
}

int main()
{
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}