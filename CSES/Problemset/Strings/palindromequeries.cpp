#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7, N = 2e5+7;
int n;
ll p1[N],p2[N],im1[N],im2[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll add(ll a, ll b)
{
    return ((a+b)%mod+mod)%mod;
}

ll sub(ll a, ll b)
{
    return ((a-b)%mod+mod)%mod;
}

ll mul(ll a, ll b)
{
    return ((a*b)%mod+mod)%mod;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

struct BIT
{
    int n;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n+1) {}
    void update(int i, ll d)
    {
        while (i<=n)
        {
            bit[i]=add(bit[i],d);
            i+=(i&-i);
        }
    }
    ll query(int i)
    {
        ll ret = 0;
        while (i)
        {
            ret=add(ret,bit[i]);
            i-=(i&-i);
        }
        return ret;
    }
    ll query(int l, int r)
    {
        return sub(query(r),query(l-1));
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>n>>q;
    string s;
    cin>>s;
    BIT fw1(n),fw2(n),bw1(n),bw2(n);
    p1[0]=p2[0]=im1[0]=im2[0]=1;
    p1[1]=uniform_int_distribution<int>(1000,10000)(rng);
    p2[1]=uniform_int_distribution<int>(1000,10000)(rng);
    im1[1]=binpow(p1[1],mod-2);
    im2[1]=binpow(p2[1],mod-2);
    for (int i=2;i<=n;++i)
    {
        p1[i]=mul(p1[i-1],p1[1]);
        p2[i]=mul(p2[i-1],p2[1]);
        im1[i]=mul(im1[i-1],im1[1]);
        im2[i]=mul(im2[i-1],im2[1]);
    }
    for (int i=1;i<=n;++i)
    {
        fw1.update(i,mul(s[i-1]-'a'+1,p1[i-1]));
        fw2.update(i,mul(s[i-1]-'a'+1,p2[i-1]));
        bw1.update(n-i+1,mul(s[i-1]-'a'+1,p1[n-i]));
        bw2.update(n-i+1,mul(s[i-1]-'a'+1,p2[n-i]));
    }
    int x,y,z,l,r;
    char C;
    ll a,b,c,d;
    while (q--)
    {
        cin>>x>>y;
        if (x==1)
        {
            cin>>C;
            fw1.update(y,mul(sub(C-'a'+1,s[y-1]-'a'+1),p1[y-1]));
            fw2.update(y,mul(sub(C-'a'+1,s[y-1]-'a'+1),p2[y-1]));
            bw1.update(n-y+1,mul(sub(C-'a'+1,s[y-1]-'a'+1),p1[n-y]));
            bw2.update(n-y+1,mul(sub(C-'a'+1,s[y-1]-'a'+1),p2[n-y]));
            s[y-1]=C;
        }
        else
        {
            cin>>z;
            l=y-1;
            r=n-z;
            a=mul(fw1.query(y,z),im1[l]);
            b=mul(fw2.query(y,z),im2[l]);
            c=mul(bw1.query(n-z+1,n-y+1),im1[r]);
            d=mul(bw2.query(n-z+1,n-y+1),im2[r]);
            if (a==c&&b==d)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}