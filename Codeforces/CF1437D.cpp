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

stack<int> s;

void solve()
{
    int n,k,cur=1,last=0,unDone=0,thisLevel=0;
    cin>>n;
    cin>>k;
    //cout<<"0: 1\n1: ";
    for (int i=1;i<n;++i)
    {
        cin>>k;
        if (last<k)
        {
            //cout<<k<<" ";
            last=k;
            ++thisLevel;
            continue;
        }
        if (unDone)
        {
            //cout<<k<<" ";
            --unDone;
            last=k;
            ++thisLevel;
            continue;
        }
        unDone=thisLevel-1;
        ++cur;
        //cout<<"\n"<<cur<<": "<<k<<" ";
        thisLevel=1;
        last=k;
    }
    cout<<cur<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}