#include <bits/stdc++.h>
using namespace std;

int c[10];
string num = "0123456789";
vector<int> v[10];

void solve()
{
    for (int i=0;i<10;++i)
    {
        c[i]=0;
        v[i].clear();
    }
    string n;
    int k,l,x;
    cin>>n;
    cin>>k;
    l=n.size();
    for (int i=0;i<l;++i)
        ++c[n[i]-'0'];
    for (int i=0;i<l&&k>0;++i)
        for (int j=0;j<(n[i]-'0');++j)
            if (c[j]>0)
            {
                --k;
                --c[j];
                v[j].push_back(n[i]-'0');
                n[i]=num[j];
            }
    for (int i=0;i<10;++i)
        sort(v[i].begin(), v[i].end());
    for (int i=l-1;i>=0;--i)
        if (!v[n[i]-'0'].empty())
        {
            x = (n[i]-'0');
            n[i] = num[v[x].back()];
            v[x].pop_back();
        }
    cout<<n<<"\n";
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