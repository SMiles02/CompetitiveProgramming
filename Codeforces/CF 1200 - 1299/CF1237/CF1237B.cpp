#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    int n,k,ans=0;
    cin>>n;
    map<int,int> a;
    int c[n];
    for (int i=0;i<n;++i)
    {
        cin>>k;
        a[k]=i;
    }
    for (int i=0;i<n;++i)
    {
        cin>>k;
        c[a[k]]=i;
    }
    k=c[0];
    for (int i=1;i<n;++i)
    {
        if (k>c[i])
        {
            ++ans;
        }
        else
        {
            k=c[i];
        }
    }
    cout<<ans;
    return 0;
}