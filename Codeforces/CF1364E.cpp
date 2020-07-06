#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
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

vector<int> v[2048];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n,k,m,x,t;
    cin>>n;
    vector<int> p(n);
    for (int i=0;i<n;++i)
        p[i]=i+1;
    while (1)
    {
        shuffle(p.begin(), p.end(), rng);
        cout<<"? "<<p[0]<<" "<<p[1]<<endl;
        cin>>k;
        if (__builtin_popcount(k)<5)
            break;
    }
    m=k;
    v[k].push_back(p[1]);
    t=k;
    for (int i=2;i<n;++i)
    {
        cout<<"? "<<p[0]<<" "<<p[i]<<endl;
        cin>>k;
        m=min(m,k);
        v[k].push_back(i);
        t&=k;
    }
    if (sz(v[m])==1)
        x=v[m][0];
    else if (t!=0)
    {
        for (int i=0;i<sz(v[m]);++i)
        {
            t=2047;
            for (int j=0;j<i;++j)
            {
                cout<<"? "<<v[m][i]<<" "<<v[m][j]<<endl;
                cin>>k;
                t&=k;
            }
            for (int j=i+1;i<sz(v[m]);++j)
            {
                cout<<"? "<<v[m][i]<<" "<<v[m][j]<<endl;
                cin>>k;
                t&=k;
            }
            if (t==0)
            {
                x=v[m][i];
                break;
            }
        }
    }
    else
        x=p[0];
    int ans[n+1];
    ans[x]=0;
    for (int i=1;i<x;++i)
    {
        cout<<"? "<<x<<" "<<i<<endl;
        cin>>k;
        ans[i]=k;
    }
    for (int i=x+1;i<=n;++i)
    {
        cout<<"? "<<x<<" "<<i<<endl;
        cin>>k;
        ans[i]=k;
    }
    cout<<"!";
    for (int i=1;i<=n;++i)
        cout<<" "<<ans[i];
    return 0;
}