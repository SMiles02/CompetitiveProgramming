#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 200;
int parent[mn],r[mn];
 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void make_set(int v) {
    for (int i=0;i<v;++i)
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    make_set(n+m);
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='#')
                union_sets(i,n+j);
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (find_set(i)==find_set(n+j))
                if (s[i][j]=='.')
                {
                    cout<<"No";
                    return 0;
                }
    cout<<"Yes";
    return 0;
}