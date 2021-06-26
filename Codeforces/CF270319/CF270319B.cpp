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
    ll ans=1;
    cin>>n>>k;
    int a[n];
    map<int,vector<int>> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        m[a[i]%k].push_back(a[i]);
    }
    for (int i=0;i<k;++i)
    {
        if (sz(m[i])>1)
        {
            cout<<0;
            return 0;
        }
    }
    for (int i=0;i<k;++i)
    {
        if (sz(m[i]))
        {
            for (int j=i+1;j<k;++j)
            {
                if (sz(m[j]))
                {
                    if (m[i][0]>m[j][0])
                    {
                        ans*=(i+k-j);
                        ans%=k;
                    }
                    else
                    {
                        ans*=(j-i);
                        ans%=k;
                    }
                }
            }
        }
    }
    cout<<ans%k;
    return 0;
}