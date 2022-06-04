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

int n,k;
int ans[35];
int other[35];

int maxNum()
{
    ll cur=1;
    for (int i=1;i<35;++i)
    {
        cur*=2;
        ++cur;
        if (cur>=n)
            return i;
    }
    return 1;
}

bool check(int a[])
{
    int curAmount=1;
    ll curScore=1;
    for (int i=0;i<k;++i)
    {
        curAmount+=a[i];
        curScore+=curAmount;
    }
    if (curScore>=n)
        return 1;
    return 0;
}

void solve()
{
    int soFar=1,next,l,r,m;
    cin>>n;
    k=maxNum();
    for (int i=0;i<k;++i)
    {
        ans[i]=i+1;
        other[i]=i+1;
    }
    for (int i=0;i<k;++i)
    {
        l=0;r=soFar;
        while (l<r)
        {
            m=l+(r-l)/2;
            for (int j=0;j<i;++j)
            {
                other[j]=ans[j];
            }
            other[i]=m;
            next=soFar+m;
            for (int j=i+1;j<k;++j)
            {
                other[j]=next;
                next*=2;
            }
            if (check(other))
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        ans[i]=l;
        soFar+=ans[i];
    }
    cout<<k<<"\n";
    for (int i=0;i<k;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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