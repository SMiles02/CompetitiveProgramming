#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000026653;

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res*a)%mod;
    return res;
}

ll subt(ll a, ll b)
{
    if (a<b)
        return a+mod-b;
    return a-b;
}

ll p1[1000001];
ll p2[1000001];
ll im1[1000001];
ll im2[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    p1[0]=1;
    p2[0]=1;
    vector<int> primes = {7994669,9458311,8950873,9535627,7676621,9660349,9924487,9444557,9558361,7559323,9971641,8053921,9962171,9562321,9112091,8062757,8397859,7986317,7243937,9020707};
    p1[1]=primes[uniform_int_distribution<int>(1,20)(rng)-1];
    p2[1]=primes[uniform_int_distribution<int>(1,20)(rng)-1];
    while (p2[1]==p1[1])
        p2[1]=primes[uniform_int_distribution<int>(1,20)(rng)-1];
    im1[0]=1;im2[0]=1;
    im1[1]=binpow(p1[1],mod-2);
    im2[1]=binpow(p2[1],mod-2);
    for (int i=2;i<1000001;++i)
    {
        p1[i]=p1[i-1]*p1[1];
        p1[i]%=mod;
        p2[i]=p2[i-1]*p2[1];
        p2[i]%=mod;
        im1[i]=im1[i-1]*im1[1];
        im1[i]%=mod;
        im2[i]=im2[i-1]*im2[1];
        im2[i]%=mod;
    }
    int n,m,ans=0;
    ll sc1=0,sc2=0;
    string s,t;
    cin>>s;
    cin>>t;
    n=sz(s);m=sz(t);
    for (int i=0;i<m;++i)
    {
        sc1+=((t[i]-'a'+1)*p1[i]);
        sc1%=mod;
        sc2+=((t[i]-'a'+1)*p2[i]);
        sc2%=mod;
    }
    ll h1[n+1];
    ll h2[n+1];
    h1[0]=0;
    h2[0]=0;
    for (int i=1;i<=n;++i)
    {
        h1[i]=h1[i-1]+((s[i-1]-'a'+1)*p1[i-1]);
        h1[i]%=mod;
        h2[i]=h2[i-1]+((s[i-1]-'a'+1)*p2[i-1]);
        h2[i]%=mod;
    }
    for (int i=m;i<=n;++i)
        if ((subt(h1[i],h1[i-m])*im1[i-m])%mod==sc1)
            if ((subt(h2[i],h2[i-m])*im2[i-m])%mod==sc2)
                ++ans;
    cout<<ans;
    return 0;
}