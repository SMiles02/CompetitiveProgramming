#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k;
string s,t,alpha="abcdefghijklmnopqrstuvwxyz";
map<char,int> a;
map<char,int> b;
vector<pair<int,int>> v;

void solve()
{
    cin>>n;
    cin>>s;
    cin>>t;
    a.clear();
    b.clear();
    for (int i=0;i<n;++i)
    {
        ++a[s[i]];
        ++b[t[i]];
    }
    for (int i=0;i<26;++i)
    {
        if ((a[alpha[i]]+b[alpha[i]])%2)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
    v.clear();
    for (int i=0;i<n-1;++i)
    {
        if (s[i]!=t[i])
        {
            for (int j=i+1;j<n;++j)
            {
                if (s[j]==s[i])
                {
                    swap(t[i],s[j]);
                    v.push_back(make_pair(j+1,i+1));
                    break;
                }
                else if (s[i]==t[j])
                {
                    v.push_back({j+1,j+1});
                    swap(s[j],t[j]);
                    swap(t[i],s[j]);
                    v.push_back(make_pair(j+1,i+1));
                    break;
                }
            }
        }
    }
    //cout<<s<<" "<<t<<"\n";
    k=sz(v);
    cout<<k<<"\n";
    for (int i=0;i<k;++i)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int z;
    cin>>z;
    while (z--)
    {
        solve();
    }
    return 0;
}