#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 4e5+7;
int parent[mn],r[mn],cyc[mn];

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
        cyc[i]=0;
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
        if (cyc[b])
            cyc[a]=1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0,x,y;
    cin>>n;
    make_set(4e5);
    while (n--)
    {
        cin>>x>>y;
        if (x==y||find_set(x)==find_set(y))
            cyc[find_set(x)]=1;
        else
            union_sets(x,y);
    }
    for (int i=1;i<400001;++i)
        if (find_set(i)==i)
        {
            if (cyc[i])
                ans+=r[i];
            else
                ans+=r[i]-1;
        }
    cout<<ans;
    return 0;
}