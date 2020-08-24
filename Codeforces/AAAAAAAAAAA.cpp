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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k,A,B,ans=0;
    cin>>n;
    cin>>k;
    cin>>A;
    cin>>B;
    //cout<<"0\n";return 0;
    while (n>1)
    {
        //cout<<n<<" "<<ans<<"\n";
        if (n<k||k==1)
        {
            cout<<ans+(n-1)*A;
            return 0;
        }
        if (n%k)
        {
            ans+=((n%k)*A);
            n-=(n%k);
            continue;
        }
        if (B>(n-(n/k))*A)
            ans+=(n-(n/k))*A;
        else
            ans+=B;
        n/=k;
    }
    cout<<ans;
    return 0;
}