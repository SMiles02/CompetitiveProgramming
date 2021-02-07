#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+1;
int pt[mn],rk[mn],ans,mx=1;
 
int find_set(int v) {
    if (v == pt[v])
        return v;
    return pt[v] = find_set(pt[v]);
}
 
void make_set(int v) {
    for (int i=1;i<=v;++i)
    {
        pt[i] = i;
        rk[i] = 1;
    }
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        pt[b] = a;
        rk[a] += rk[b];
        --ans;
        mx=max(mx,rk[a]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    ans=n;
    make_set(n);
    while (m--)
    {
        cin>>x>>y;
        union_sets(x,y);
        cout<<ans<<" "<<mx<<"\n";
    }
    return 0;
}