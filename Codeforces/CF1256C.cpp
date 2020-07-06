#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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

int ans[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,d,x,cur=0,s,e;
    bool b;
    cin>>n>>m>>d;
    int len[m+1];
    int startP[m+1];
    int endP[m+1];
    for (int i=1;i<=m;++i)
    {
        cin>>x;
        len[i]=x;
        startP[i]=cur;
        for (int j=cur;j<cur+x;++j)
            ans[j]=i;
        cur+=x;
        endP[i]=cur-1;
    }
    cur=n;
    /**for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";**/
    for (int i=m;i;--i)
    {
        s=startP[i];
        e=endP[i];
        cur-=d;
        if (cur<=e)
            break;
        for (int j=s;j<=e;++j)
            ans[j]=0;
        /**for (int i=0;i<n;++i)
            cout<<ans[i]<<" ";
        cout<<"\n";**/
        for (int j=cur-len[i]+1;j<=cur;++j)
            ans[j]=i;
        cur=cur-len[i]+1;
    }
    cur=-1;
    while (cur+d<n)
    {
        b=1;
        for (int i=cur+1;i<=cur+d;++i)
            if (ans[i])
            {
                cur=i;
                b=0;
                break;
            }
        if (b)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    return 0;
}