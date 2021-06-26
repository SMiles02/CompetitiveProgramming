#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

int a[3];
string s[3];

void solve()
{
    int n,x;
    cin>>n;
    for (int i=0;i<3;++i)
        cin>>s[i];
    for (int i=0;i<3;++i)
    {
        x=0;
        for (auto j : s[i])
            x+=(j-'0');
        if (x>n)
            a[i]=1;
        else
            a[i]=0;
    }
    for (int x=0;x<3;++x)
        for (int y=x+1;y<3;++y)
            if (a[x]==a[y])
            {
                vector<int> v={-1},w={-1};
                for (int i=0;i<n*2;++i)
                    if ((s[x][i]-'0')==a[x])
                        v.push_back(i);
                for (int i=0;i<n*2;++i)
                    if ((s[y][i]-'0')==a[y])
                        w.push_back(i);
                for (int i=1;i<=n;++i)
                {
                    for (int j=v[i-1]+1;j<v[i];++j)
                        cout<<s[x][j];
                    for (int j=w[i-1]+1;j<w[i];++j)
                        cout<<s[y][j];
                    cout<<a[x];
                }
                for (int j=v[n]+1;j<n*2;++j)
                    cout<<s[x][j];
                for (int j=w[n]+1;j<n*2;++j)
                    cout<<s[y][j];
                cout<<"\n";
                return;
            }
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