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
    int n,k,mini=0;
    cin>>n;
    int a[n];
    a[0]=0;
    for (int i=1;i<n;++i)
    {
        cin>>k;
        a[i]=a[i-1]+k;
        mini=min(mini,a[i]);
    }
    map<int,int> m;
    k=1-mini;
    for (int i=0;i<n;++i)
    {
        a[i]+=k;
        if (m[a[i]]||a[i]>n||a[i]<1)
        {
            cout<<-1;
            return 0;
        }
        m[a[i]]=1;
    }
    for (int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}