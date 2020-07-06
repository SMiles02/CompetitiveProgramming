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
    int n,x;
    cin>>n>>x;
    int a[n];
    map<int,vector<int>> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        m[a[i]].push_back(i+1);
    }
    for (int i=0;i<n;++i)
    {
        if (sz(m[x-a[i]]))
        {
            if (a[i]*2==x)
            {
                if (sz(m[a[i]])>1)
                {
                    cout<<m[a[i]][0]<<" "<<m[a[i]][1]<<"\n";
                    return 0;
                }
            }
            else
            {
                cout<<i+1<<" "<<m[x-a[i]][0];
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}