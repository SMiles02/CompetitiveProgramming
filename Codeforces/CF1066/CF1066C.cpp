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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,mini=0,maxi=0,k;
    int a[200001];
    cin>>q;
    string s;
    for (int i=0;i<q;++i)
    {
        if (!i)
        {
            cin>>s;
            cin>>k;
            a[k]=0;
            continue;
        }
        cin>>s;
        cin>>k;
        if (s=="?")
            cout<<min(a[k]-mini,maxi-a[k])<<"\n";
        else if (s=="L")
        {
            --mini;
            a[k]=mini;
        }
        else
        {
            ++maxi;
            a[k]=maxi;
        }
    }
    return 0;
}