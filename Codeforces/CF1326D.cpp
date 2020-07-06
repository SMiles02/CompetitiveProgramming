#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int p;
ll powers[1000000];
int mod=1000000007;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
    {
        return (res * a)%mod;
    }
    return res;
}

void solve()
{
    string s,t="";
    cin>>s;
    int n=sz(s),num=n,m,x=0,y=0;
    ll z;
    for (int i=0;i<n;++i)
    {
        if (s[i]!=s[n-1-i])
        {
            num=i;
            break;
        }
    }
    if (num*2>=n)
    {
        cout<<s<<"\n";
        return;
    }
    for (int i=num;i<n-num;++i)
    {
        t+=s[i];
    }
    //cout<<"t = "<<t<<"\n";
    m=sz(t);
    ll pre[m];
    ll suff[m];
    pre[0]=(t[0]-'a'+1);
    suff[m-1]=(t[m-1]-'a'+1);
    for (int i=1;i<m;++i)
    {
        pre[i]=(pre[i-1]+(powers[i])*(t[i]-'a'+1))%mod;
        suff[m-1-i]=(suff[m-i]+(powers[i])*(t[m-1-i]-'a'+1))%mod;
    }
    /**for (int i=0;i<m;++i)
    {
        cout<<pre[i]<<" ";
    }
    cout<<"\n";
    for (int i=0;i<m;++i)
    {
        cout<<suff[i]<<" ";
    }
    cout<<"\n";**/
    for (int i=m-2;i>=0;--i)
    {
        //a*binpow(b,mod-2);
        z=suff[0]-suff[i+1];
        if (z<0)
        {
            z+=mod;
        }
        z=z*(binpow(powers[m-i-1],mod-2));
        z%=mod;
        //cout<<"i: "<<i<<": "<<z<<" "<<pre[i]<<"\n";
        if (pre[i]==z)
        {
            x=i+1;
            break;
        }
    }
    for (int i=1;i<m;++i)
    {
        z=pre[m-1]-pre[i-1];
        if (z<0)
        {
            z+=mod;
        }
        z=z*(binpow(powers[i],mod-2));
        z%=mod;
        //cout<<"i: "<<i<<": "<<z<<" "<<suff[i]<<"\n";
        if (suff[i]==z)
        {
            y=m-i;
            break;
        }
    }
    //cout<<x<<" "<<y<<"\n";
    for (int i=0;i<num;++i)
    {
        cout<<s[i];
    }
    if (x>y)
    {
        for (int i=0;i<x;++i)
        {
            cout<<t[i];
            //cout<<i;
        }
    }
    else
    {
        for (int i=m-y;i<m;++i)
        {
            cout<<t[i];
            //cout<<i;
        }
    }
    for (int i=n-num;i<n;++i)
    {
        cout<<s[i];
    }
    cout<<"\n";
    return;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin>>n;
    vector<int> primes={29,31,37,41,43,47,53};
    p=primes[uniform_int_distribution<int>(1,7)(rng)-1];
    powers[0]=1;
    powers[1]=p;
    for (int i=2;i<1000000;++i)
    {
        powers[i]=(powers[i-1]*p)%mod;
        //cout<<powers[i]<<"\n";
    }
    //cout<<p<<" <= p\n";
    while (n--)
    {
        solve();
    }
    //cout<<p;
    return 0;
}