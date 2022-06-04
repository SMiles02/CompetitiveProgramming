#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 6e5+69;
int parent[mn],r[mn];
 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void make_set(int v) {
    for (int i=0;i<=v;++i)
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

void solve()
{
    int n;
    cin>>n;
    make_set(2*n+2);
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='L')
            union_sets(n+1+i,i+1);
        else
            union_sets(i,n+i+2);
    }
    for (int i=0;i<=n;++i)
        cout<<r[find_set(i)]<<" ";
    cout<<"\n";
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