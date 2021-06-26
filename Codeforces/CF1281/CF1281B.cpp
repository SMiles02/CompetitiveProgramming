#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s,c,alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ",ideal;
int n,m,k;
map<char,vector<int>> a;
map<char,vector<int>> b;
map<char,int> alphaNums;

int stringCompare()
{
    for (int i=0;i<min(n,m);++i)
    {
        if (s[i]!=c[i])
        {
            if (alphaNums[s[i]]>alphaNums[c[i]])
            {
                return 1;
            }
            return 0;
        }
    }
    if (n==m)
    {
        return -1;
    }
    if (n>m)
    {
        return 1;
    }
    return 0;
}

void solve()
{
    cin>>s>>c;
    n=sz(s);m=sz(c);
    ideal=s;
    sort(ideal.begin(), ideal.end());
    for (int i=0;i<n;++i)
    {
        if (ideal[i]!=s[i])
        {
            for (int j=i+1;j<n;++j)
            {
                if (s[j]==ideal[i])
                {
                    swap(s[i],s[j]);
                    if (!stringCompare())
                    {
                        cout<<s<<"\n";
                        return;
                    }
                    swap(s[i],s[j]);
                    break;
                }
            }
            for (int j=n-1;j>i;--j)
            {
                if (s[j]==ideal[i])
                {
                    swap(s[i],s[j]);
                    if (!stringCompare())
                    {
                        cout<<s<<"\n";
                        return;
                    }
                    swap(s[i],s[j]);
                    break;
                }
            }
            cout<<"---\n";
            return;
        }
    }
    if (!stringCompare())
    {
        cout<<s<<"\n";
        return;
    }
    cout<<"---\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<26;++i)
    {
        alphaNums[alpha[i]]=i;
    }
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}