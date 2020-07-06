#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    string s;
    cin>>n;
    cin>>s;
    vector<int> v;
    for (int i=0;i<n-1;++i)
    {
        if (s[i]=='B')
        {
            s[i]='W';
            if (s[i+1]=='W')
            {
                s[i+1]='B';
            }
            else
            {
                s[i+1]='W';
            }
            v.push_back(i+1);
        }
    }
    if (s[n-1]=='W')
    {
        k=sz(v);
        cout<<k<<"\n";
        for (int i=0;i<k;++i)
        {
            cout<<v[i]<<" ";
        }
        return 0;
    }
    for (int i=0;i<n-1;++i)
    {
        if (s[i]=='W')
        {
            s[i]='B';
            if (s[i+1]=='B')
            {
                s[i+1]='W';
            }
            else
            {
                s[i+1]='B';
            }
            v.push_back(i+1);
        }
    }
    if (s[n-1]=='B')
    {
        k=sz(v);
        cout<<k<<"\n";
        for (int i=0;i<k;++i)
        {
            cout<<v[i]<<" ";
        }
        return 0;
    }
    cout<<-1;
    return 0;
}