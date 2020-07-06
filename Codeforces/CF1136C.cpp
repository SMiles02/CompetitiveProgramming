#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,flag=0;
int a[500][500];
int b[500][500];

void solve(int x, int y)
{
    multiset<int> s;
    multiset<int> t;
    while (x>=0&&y>=0&&x<n&&y<m)
    {
        s.insert(a[x][y]);
        t.insert(b[x][y]);
        ++x;
        --y;
    }
    if (s!=t) flag=1;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>b[i][j];
    for (int j=0;j<m;++j)
        solve(0,j);
    for (int i=1;i<n;++i)
        solve(i,m-1);
    if (flag)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}