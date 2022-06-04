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
    int n,k,adder=0;
    cin>>n>>k;
    if (n%2)
    {
        adder=1;
        --n;
    }
    n/=2;
    if (n>k)
    {
        cout<<-1;
        return 0;
    }
    if (n==0)
    {
        if (k==0)
        {
            cout<<5;
        }
        else
        {
            cout<<-1;
        }
        return 0;
    }
    if (n==1)
    {
        cout<<k<<" "<<2*k;
        if (adder)
        {
            cout<<" "<<3*k;
        }
        return 0;
    }
    else
    {
        int g=k-n+1,cur=1;
        cout<<g<<" "<<2*g<<" ";
        --n;
        k=n;
        for (int i=0;i<n;++i)
        {
            while (cur==g||cur==2*g||cur+1==g||cur+1==2*g)
            {
                cur+=2;
            }
            cout<<cur<<" "<<cur+1<<" ";
            cur+=2;
        }
        if (adder)
        {
            cout<<999999999;
        }
    }
    return 0;
}