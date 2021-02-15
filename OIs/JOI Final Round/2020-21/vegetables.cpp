#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
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
    int n,cur=0,ans,lt;
    cin>>n;
    int a[n],s[n+1],h[n+1],mV[n+1];
    for (int i=0;i<n;++i)
        cin>>a[i];
    s[n]=s[n-1]=mV[n]=mV[n-1]=0;
    h[n-1]=a[n-1];
    for (int i=n-2;i>=0;--i)
    {
        s[i]=s[i+1]+max(0,a[i+1]+1-a[i]);
        
        h[i]=max(a[i],h[i+1]+1);
    }
    for (int i=0;i<n;++i)
        cout<<s[i]<<" ";
    cout<<"\n";
    ans=s[0];
    lt=a[0];
    for (int i=1;i<n;++i)
    {
        cur+=max(0,a[i-1]+1-a[i]);
        lt=max(lt+1,a[i]);
        //cout<<cur<<" "<<s[i+1]<<"\n";
        ans=min(ans,cur+s[i+1]+max(0,h[i+1]+1-lt));
    }
    cout<<ans;
    return 0;
}