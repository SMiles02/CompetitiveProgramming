#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int mn = 2e5+7;
int parent[mn],r[mn];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    for (int i=1;i<=v;++i)
    {
        parent[i] = i;
        r[i] = 1;
    }
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        r[a] += r[b];
    }
}

bitset<mn> stuck;

void solve()
{
    int n,k,ok=0,p=0,x,y;
    cin>>n>>k;
    int a[k+1][2];
    map<int,int> X;
    map<int,int> Y;
    make_set(k);
    for (int i=1;i<=k;++i)
    {
        cin>>x>>y;
        a[i][0]=x;a[i][1]=y;
        X[x]=i;
        Y[y]=i;
    }
    for (int i=1;i<=k;++i)
    {
        if (a[i][0]==a[i][1])
        {
            ++ok;
            stuck[i]=0;
        }
        else
        {
            if (X[a[i][1]]&&Y[a[i][0]])
            {
                stuck[i]=1;
                union_sets(i,X[a[i][1]]);
                union_sets(i,Y[a[i][0]]);
            }
            else
                stuck[i]=0;
        }
    }
    for (int i=1;i<=k;++i)
        if (stuck[i])
            --r[find_set(i)];
    for (int i=1;i<=k;++i)
        if (stuck[i]&&find_set(i)==i&&r[i]==0)
            ++p;
    //cout<<k<<" "<<ok<<" "<<p<<"\n";
    cout<<k-ok+p<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}